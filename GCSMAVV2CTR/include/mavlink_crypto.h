#pragma once

/**
  * MAVLink v1.0 Crypto-headers
  * @Author: Mark Seidenschnur
  * Description: Headers adding the Chaskey signature scheme
  * and AES encryption.
  */

#ifndef  _MAVLINK_CRYPTO_H_
#define  _MAVLINK_CRYPTO_H_

#include "crypto/chaskey.c"
#include "crypto/aes.c"
#include "crypto/ecdh.c"

#ifndef MAVLINK_CRYPTO
#define MAVLINK_CRYPTO
#endif

MAVLINK_CRYPTO void chaskey_sign(const uint8_t* msg, const uint8_t len, uint8_t* tag, uint32_t tlen, uint8_t* key)
{
    uint32_t k[4], k1[4], k2[4];

    uint32_t u;
    for(unsigned int i = 0; i < 4; i++)
    {
    	u = key[0];
	    u = (u << 8) + key[4*i + 0];
	    u = (u << 8) + key[4*i + 1];
	    u = (u << 8) + key[4*i + 2];

	    k[i] = u;
    }

	uint32_t taglen = tlen;
	uint32_t msglen = len;
	
	subkeys(k1,k2,k);
	chaskey(tag, taglen, msg, msglen, k, k1, k2);

}

MAVLINK_CRYPTO void aes_encrypt(uint8_t* cipher, uint8_t len, uint8_t* key, uint8_t* nonce)
{
	struct AES_ctx ctx;
	uint32_t msglen = (uint32_t)len;

	uint8_t iv[16];
	memset(iv, 0x00, 16);
	memcpy(iv, nonce, 6);

	AES_init_ctx_iv(&ctx, key, iv);
	AES_CTR_xcrypt_buffer(&ctx, cipher, msglen);
}

MAVLINK_CRYPTO void aes_decrypt(uint8_t* msg, uint8_t len, uint8_t* key, uint8_t* nonce)
{
	struct AES_ctx ctx;
	uint32_t msglen = (uint32_t)len;

	uint8_t iv[16];
	memset(iv, 0x00, 16);
	memcpy(iv, nonce, 6);

	AES_init_ctx_iv(&ctx, key, iv);
	AES_CTR_xcrypt_buffer(&ctx, msg, msglen);
}


#endif /* _MAVLINK_HELPERS_H_ */