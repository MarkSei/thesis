/*******************************************************************************
 Copyright (C) 2010  Bryan Godbolt godbolt ( a t ) ualberta.ca
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 ****************************************************************************/
/*
 This program sends some data to qgroundcontrol using the mavlink protocol.  The sent packets
 cause qgroundcontrol to respond with heartbeats.  Any settings or custom commands sent from
 qgroundcontrol are printed by this program along with the heartbeats.
 
 
 I compiled this program sucessfully on Ubuntu 10.04 with the following command
 
 gcc -I ../../pixhawk/mavlink/include -o udp-server udp-server-test.c
 
 the rt library is needed for the clock_gettime on linux
 */
/* These headers are for QNX, but should all be standard on unix/linux */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#if (defined __QNX__) | (defined __QNXNTO__)
/* QNX specific headers */
#include <unix.h>
#else
/* Linux / MacOS POSIX timer headers */
#include <sys/time.h>
#include <time.h>
#include <arpa/inet.h>
#include <stdbool.h> /* required for the definition of bool in C99 */
#endif

/* This assumes you have the mavlink headers on your include path
 or in the same folder as this source file */
#include <mavlink.h>


#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

uint64_t microsSinceEpoch();

int main(int argc, char* argv[])
{
	
	
	//struct sockaddr_in fromAddr;
	uint8_t buf[BUFFER_LENGTH];
	ssize_t recsize;
	socklen_t fromlen;
	int bytes_sent;
	mavlink_message_t msg;
	uint16_t len;
	//int success = 0;
	unsigned int temp = 0;
	

	uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
	uint8_t* role;

	mavlink_init_secure_chan(key, MAVLINK_ROLE_GCS, MAVLINK_COMM_0);

	mavlink_status_t* status = mavlink_get_channel_status(MAVLINK_COMM_0);

	for(unsigned int i = 0; i < 16; i++) printf("%02x ", status->secure_state.key_send_enc[i]);
	printf("\n");
	for(unsigned int i = 0; i < 16; i++) printf("%02x ", status->secure_state.key_rec_enc[i]);
	printf("\n");

	
	int s = 5;
	
	for (unsigned int j = 0; j < 2; j++) 
    {
		
		/*Send Heartbeat */
		mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, 0, 0, 0);
		len = mavlink_msg_to_send_buffer(buf, &msg);

		printf("ENCRYPTED: \n");
		for(unsigned int i = 0; i < msg.len; i++) printf("%02x ", (uint8_t)_MAV_PAYLOAD(&msg)[i]);
		printf("\n");
		//bytes/_sent = sendto(sock, buf, len, 0, (struct sockaddr*)&gcAddr, sizeof(struct sockaddr_in));
		
		
		//mavlink_msg_heartbeat_decode(&msg, &heartbeat);
		

		
			// Something received - print out all bytes and parse packet
		//mavlink_init_secure_chan(key, role, MAVLINK_COMM_0);

		mavlink_message_t msg_rec;
		mavlink_status_t* status_rec;
		mavlink_heartbeat_t heartbeat;

		
		//printf("Bytes Received: %d\nDatagram: ", (int)recsize);
		for (unsigned int i = 0; i < len; ++i)
		{
			temp = buf[i];
			//printf("%02x ", (unsigned char)temp);
			if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg_rec, status))
			{
				// Packet received
				//mavlink_msg_heartbeat_decode(&msg, &hb);
				if(msg_rec.msgid == 0)
				{
					printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg_rec.sysid, msg_rec.compid, msg_rec.len, msg_rec.msgid);
				}

				
				//printf("\nPayload: %d\n", hb.type);
			} 
		}
		//printf("\n");
		
		memset(buf, 0, BUFFER_LENGTH);

		printf("DECRYPTED: \n");
		for(unsigned int i = 0; i < msg_rec.len; i++) printf("%02x ", (uint8_t)_MAV_PAYLOAD(&msg_rec)[i]);
		printf("\n");

		mavlink_msg_heartbeat_decode(&msg_rec, &heartbeat);
		printf("\nPayload: %d, %d, %02x\n", heartbeat.autopilot, heartbeat.type, heartbeat.tag[0]);
	    //printf("\n");
		
		/**
		memset(buf, 0, BUFFER_LENGTH);
		recsize = recvfrom(sock, (void *)buf, BUFFER_LENGTH, 0, (struct sockaddr *)&locAddr, &fromlen);
		

		if (recsize > 0)
      	{
			// Something received - print out all bytes and parse packet
			mavlink_message_t msg;
			mavlink_status_t status;

			mavlink_heartbeat_t hb;

			
			
			//printf("Bytes Received: %d\nDatagram: ", (int)recsize);
			for (i = 0; i < recsize; ++i)
			{
				temp = buf[i];
				//printf("%02x ", (unsigned char)temp);
				if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status))
				{
					// Packet received
					mavlink_msg_heartbeat_decode(&msg, &hb);
					if(msg.msgid == 0)
					{
						printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);
					}
					
					//printf("\nPayload: %d\n", hb.type);
				}
			}
			//printf("\n");
		}
		memset(buf, 0, BUFFER_LENGTH);

		**/
		//sleep(1); // Sleep one second
    }

}


