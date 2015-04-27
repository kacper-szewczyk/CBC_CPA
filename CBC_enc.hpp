/*
 * CBC_enc.h
 *
 *  Created on: 21 kwi 2015
 *      Author: kszewcz2
 */

#ifndef CBC_ENC_HPP_
#define CBC_ENC_HPP_
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define KEYLENGTH 192


void init(unsigned char *iv);

void hex_print(const void* pv, size_t len);

unsigned char* encMessage(unsigned char *message,
		size_t inputslength, unsigned char *iv);

#endif /* CBC_ENC_H_ */
