#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <assert.h>

#include <common/mavlink.h>

#define BUFSIZE 2041 //1024

int print_buffer(uint8_t* buf, uint16_t len) {

    if (len > MAVLINK_MAX_PACKET_LEN || len < MAVLINK_NUM_NON_PAYLOAD_BYTES + 1) return 0;

    for (unsigned int i = 0; i < len; ++i) printf("%02x", buf[i]);

    return 1;
}

int main(void) {

	struct timeval tv;

	gettimeofday(&tv, NULL);

	uint64_t curr = (tv.tv_sec - 1420070400) * 100000 + tv.tv_usec / 10;

	static uint8_t puba[ECC_PUB_KEY_SIZE];
	static uint8_t prva[ECC_PRV_KEY_SIZE];
	static uint8_t seca[ECC_PUB_KEY_SIZE];
	static uint8_t pubb[ECC_PUB_KEY_SIZE];
	static uint8_t prvb[ECC_PRV_KEY_SIZE];
	static uint8_t secb[ECC_PUB_KEY_SIZE];
	
	for(unsigned int i = 0; i < ECC_PRV_KEY_SIZE; ++i) prva[i] = i;
	for(unsigned int i = 0; i < ECC_PRV_KEY_SIZE; ++i) prvb[i] = ECC_PRV_KEY_SIZE - i;

	assert(ecdh_generate_keys(puba, prva));
	assert(ecdh_generate_keys(pubb, prvb));

	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
	mavlink_message_t sign_msg;

	mavlink_msg_ecdh_key_exchange_pack(1, 200, &sign_msg, pubb, 1, 200, curr);

	uint8_t buf[BUFSIZE];
	uint16_t len;
	
	len = mavlink_msg_to_send_buffer(buf, &sign_msg);

	mavlink_message_t sign_msg_rec;
	mavlink_ecdh_key_exchange_t ecdh_key;

	for (unsigned int i = 0; i < len; ++i)
	{
		//printf("%02x ", (unsigned char)temp);
		if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &sign_msg_rec, status))
		{
			// Packet received
			//mavlink_msg_heartbeat_decode(&msg, &hb);
			if(sign_msg_rec.msgid == 0)
			{
				len = mavlink_msg_to_send_buffer(buf, &sign_msg_rec);
				assert(print_buffer(buf,len));
			}
			mavlink_msg_ecdh_key_exchange_decode(&sign_msg_rec, &ecdh_key);

		} 
	}

	assert(ecdh_shared_secret(prva, ecdh_key.public_key, seca));
	assert(print_buffer(seca, ECC_PRV_KEY_SIZE));

	printf("\n");

	assert(ecdh_shared_secret(prvb, puba, secb));
	assert(print_buffer(secb, ECC_PRV_KEY_SIZE));

	// Check that identical shared secret was generated
	assert(!memcmp(seca,secb,ECC_PUB_KEY_SIZE));

	// Set signing with shared secret
	mavlink_signing_t signing;
	mavlink_signing_streams_t signing_streams;

	memcpy(signing.secret_key, seca, 32);

	signing.link_id = (uint8_t) MAVLINK_COMM_0;
	signing.timestamp = curr;
	signing.flags = MAVLINK_SIGNING_FLAG_SIGN_OUTGOING;
	
	mavlink_init_secure_chan(&signing, MAVLINK_ROLE_GCS);

	status = mavlink_get_channel_status(MAVLINK_COMM_1);
	status->signing = &signing;
	status->signing_streams = &signing_streams;


	// encrypted and signed heartbeat message
	uint8_t heart_buf[BUFSIZE];
	mavlink_message_t msg;
	mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, 0, 0, 0);

	len = 0;
	len = mavlink_msg_to_send_buffer(heart_buf, &msg);

	printf("\n");
	assert(print_buffer(heart_buf,len));
	printf("\n");

	mavlink_init_secure_chan(&signing, MAVLINK_ROLE_UAV);
	mavlink_message_t msg_rec;
	mavlink_heartbeat_t heartbeat;

	for (unsigned int i = 0; i < len; ++i)
	{
	//printf("%02x ", (unsigned char)temp);
		if (mavlink_parse_char(MAVLINK_COMM_0, heart_buf[i], &msg_rec, status))
		{
			if(msg_rec.msgid == 0)
			{
				//mavlink_msg_heartbeat_decode(&msg_rec, &heartbeat);
				//len = mavlink_msg_to_send_buffer(heart_buf, &msg_rec);
				assert(print_buffer(heart_buf,len));
			}
			mavlink_msg_heartbeat_decode(&msg_rec, &heartbeat);
		} 

	}

	printf("\n");
	
	return 0;
}