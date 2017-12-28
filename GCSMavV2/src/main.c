#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#include <common/mavlink.h>

#define BUFSIZE 2041 //1024

int main(void) {

	struct timeval tv;

	gettimeofday(&tv, NULL);

	uint64_t curr = (tv.tv_sec - 1420070400) * 100000 + tv.tv_usec / 10;

	mavlink_signing_t signing;
	mavlink_signing_streams_t signing_streams;

	uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c,
					  0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };


	memcpy(signing.secret_key, key, 32);
	signing.link_id = (uint8_t) MAVLINK_COMM_0;
	signing.timestamp = curr;
	signing.flags = MAVLINK_SIGNING_FLAG_SIGN_OUTGOING;
	
	mavlink_init_secure_chan(&signing, MAVLINK_ROLE_GCS);

	for(unsigned int i = 0; i < 16; ++i) printf("%02x", signing.key_send_enc[i]);
	printf("\n");
	for(unsigned int i = 0; i < 16; ++i) printf("%02x", signing.key_rec_enc[i]);
	printf("\n");
	for(unsigned int i = 0; i < 16; ++i) printf("%02x", signing.key_send_auth[i]);
	printf("\n");
	for(unsigned int i = 0; i < 16; ++i) printf("%02x", signing.key_rec_auth[i]);
	printf("\n");
	for(unsigned int i = 0; i < 16; ++i) printf("%02x", signing.iv[i]);
	printf("\n");

	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
	status->signing = &signing;

	
	status->signing_streams = &signing_streams;

	
	mavlink_message_t msg;
	mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, 0, 0, 0);

	uint8_t buf[BUFSIZE];
	uint16_t len;
	len = mavlink_msg_to_send_buffer(buf, &msg);

	for(unsigned int i = 0; i < len; ++i) printf("%02x ", buf[i]);
	printf("\n");
	
	printf("%d\n", msg.len);


	
	return 0;
}