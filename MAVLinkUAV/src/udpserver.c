/* 
 * udpserver.c - A simple UDP echo server 
 * usage: udpserver <port>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "mavlink.h"

#define BUFSIZE 2041 //1024

/*
 * error - wrapper for perror
 */
void udpservererror(char *msg) {
  perror(msg);
  exit(1);
}

int udpserver(int argc, char **argv) {
  int sockfd; /* socket */
  int portno; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct hostent *hostp; /* client host info */
  char buf[BUFSIZE]; /* message buf */
  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */
  int n; /* message byte size */

  /* 
   * check command line arguments 
   */
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);

  /* 
   * socket: create the parent socket 
   */
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) 
    udpservererror("ERROR opening socket");

  /* setsockopt: Handy debugging trick that lets 
   * us rerun the server immediately after we kill it; 
   * otherwise we have to wait about 20 secs. 
   * Eliminates "ERROR on binding: Address already in use" error. 
   */
  optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, 
         (const void *)&optval , sizeof(int));

  /*
   * build the server's Internet address
   */
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons((unsigned short)portno);

  /* 
   * bind: associate the parent socket with a port 
   */
  if (bind(sockfd, (struct sockaddr *) &serveraddr, 
       sizeof(serveraddr)) < 0) 
    udpservererror("ERROR on binding");

  /* 
   * main loop: wait for a datagram, then echo it
   */
  clientlen = sizeof(clientaddr);
  while (1) {

    /*
     * recvfrom: receive a UDP datagram from a client
     */
    bzero(buf, BUFSIZE);
    n = recvfrom(sockfd, buf, BUFSIZE, 0,
         (struct sockaddr *) &clientaddr, &clientlen);
    if (n < 0)
      udpservererror("ERROR in recvfrom");

    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    mavlink_init_secure_chan(key, MAVLINK_ROLE_UAV, MAVLINK_COMM_0);

    mavlink_message_t msg_rec;
    mavlink_heartbeat_t heartbeat;

    mavlink_status_t* status_rec;
    mavlink_status_t* status = mavlink_get_channel_status(MAVLINK_COMM_0);

    printf("\n");
    for(unsigned int i = 0; i < 16; i++) printf("%02x ", status->secure_state.key_rec_enc[i]);
    
    //printf("Bytes Received: %d\nDatagram: ", (int)recsize);
    for (unsigned int i = 0; i < n; ++i)
    {
      //printf("%02x ", (unsigned char)temp);
      if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg_rec, status))
      {
        // Packet received
        //mavlink_msg_heartbeat_decode(&msg, &hb);
        if(msg_rec.msgid == 0)
        {
          printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg_rec.sysid, msg_rec.compid, msg_rec.len, msg_rec.msgid);
        }
        mavlink_msg_heartbeat_decode(&msg_rec, &heartbeat);
        
        //printf("\nPayload: %d\n", hb.type);
      } 
    }

    printf("\n");
    for(unsigned int i = 0; i < msg_rec.len; i++) printf("%02x ", (uint8_t)_MAV_PAYLOAD(&msg_rec)[i]);
    printf("\n%d", heartbeat.type);
    /* 
     * gethostbyaddr: determine who sent the datagram
     */
    hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
              sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      udpservererror("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      udpservererror("ERROR on inet_ntoa\n");
    printf("server received datagram from %s (%s)\n", 
       hostp->h_name, hostaddrp);
    printf("server received %d/%d bytes: %s\n", strlen(buf), n, buf);
    
    /* 
     * sendto: echo the input back to the client 
     */
    n = sendto(sockfd, buf, n, 0, 
           (struct sockaddr *) &clientaddr, clientlen);
    if (n < 0) 
      udpservererror("ERROR in sendto");
  }
}


int main(int argc, char **argv) {
  int status;
  status = udpserver(argc, argv);
  
  return status;
}