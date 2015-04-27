#include "CBC_enc.hpp"

void init(unsigned char *iv)
{
	//RAND_bytes(iv, AES_BLOCK_SIZE);
	int i=0;
	for(i=0;i<16;i++)
	{
		iv[i]=0;
	}
}

// a simple hex-print routine. could be modified to print 16 bytes-per-line
void hex_print(const void* pv, size_t len)
{
    const unsigned char * p = (const unsigned char*)pv;
    if (NULL == pv)
        printf("NULL");
    else
    {
        size_t i = 0;
        for (; i<len;++i)
            printf("%02X ", *p++);
    }
    printf("\n");
}

unsigned char* encMessage(unsigned char *message,
		size_t inputslength, unsigned char *iv)
{
	unsigned char *aes_key =
	    		(unsigned char*)malloc(sizeof(unsigned char)
	    				* (KEYLENGTH/8));
	memset(aes_key, 0, KEYLENGTH/8);
    const size_t encslength =
    		((inputslength + AES_BLOCK_SIZE)
    				/ AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
	unsigned char *iv_old=(unsigned char*)malloc(sizeof(unsigned char)
			* AES_BLOCK_SIZE);
	strcpy((char*)iv_old,(const char*)iv);
	unsigned char *enc_out =
				(unsigned char*)malloc(sizeof(unsigned char)
						* encslength);
    AES_KEY enc_key;
    /*
    printf("\n\n IV: ");
    hex_print(iv,16);*/
    AES_set_encrypt_key(aes_key, KEYLENGTH, &enc_key);

    AES_cbc_encrypt(message, enc_out, inputslength,
    		&enc_key, iv, AES_ENCRYPT);
    /*
    printf("\n\n IV: ");
    hex_print(iv,16);*/
    printf("encrypt:\t");
    hex_print(enc_out, encslength);
    int i=0;
    for(i=0;i<AES_BLOCK_SIZE;i++)
    {
    	iv[i]=iv_old[i]^255;
    	//iv[i]=iv_old[i];
    }
    //iv[AES_BLOCK_SIZE-1]++;
    /*
    printf("\n\n IV: ");
    hex_print(iv,16);*/
    return enc_out;
}
