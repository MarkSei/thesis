/* 
 * udpclient.c - A simple UDP client
 * usage: udpclient <host> <port>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#include <common/mavlink.h>

#define BUFSIZE 2041 //1024

/* 
 * error - wrapper for perror
 */
void udpclienterror(char *msg) {
    perror(msg);
    exit(0);
}


int main(int argc, char **argv) {
    int sockfd, portno, n;
    int serverlen;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    char buf[BUFSIZE];

    /* check command line arguments */
    if (argc != 3) {
       fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
       exit(0);
    }
    hostname = argv[1];
    portno = atoi(argv[2]);

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
        udpclienterror("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
	  (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    /* get a message from the user */
    bzero(buf, BUFSIZE);
    //printf("Please enter msg: ");
    //fgets(buf, BUFSIZE, stdin);

    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    mavlink_init_secure_chan(key, MAVLINK_ROLE_GCS, MAVLINK_COMM_0);

    mavlink_message_t msg;

    mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, 0, 0, 0);

    uint16_t len;
    len = mavlink_msg_to_send_buffer(buf, &msg);

    printf("\nmessage to send: ");
    for(unsigned int i = 0; i < len; i++) printf("%02x ", (uint8_t)buf[i]);
    printf("\n");
    /* send the message to the server */
    serverlen = sizeof(serveraddr);
    n = sendto(sockfd, buf, len, 0, &serveraddr, serverlen);
    if (n < 0) 
      udpclienterror("ERROR in sendto");
    
    /* print the server's reply */
    n = recvfrom(sockfd, buf, len, 0, &serveraddr, &serverlen);
    if (n < 0) 
      udpclienterror("ERROR in recvfrom");
    printf("Echo from server: ");
    for(unsigned int i = 0; i < n; i++) printf("%02x ", (uint8_t)buf[i]);
    printf("\n");
    return 0;
}