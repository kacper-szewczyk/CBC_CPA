#include "CBC_enc.hpp"
#define MESSAGELENGTH 100



int main(int argc, char **argv)
{
	unsigned char *iv=(unsigned char*)malloc(sizeof(unsigned char)
			* AES_BLOCK_SIZE);
	srand(time(NULL));
	init(iv);

    unsigned char *message1=(unsigned char*)malloc(sizeof(unsigned char)
			* MESSAGELENGTH);
    unsigned char *message2=(unsigned char*)malloc(sizeof(unsigned char)
			* MESSAGELENGTH);
    memset(message1, 0, MESSAGELENGTH);
    memset(message2, 255, MESSAGELENGTH);
    /*
    printf("Message 1: ");
    hex_print(message1,MESSAGELENGTH);
    printf("Message 2: ");
    hex_print(message2,MESSAGELENGTH);
    */
    const size_t encslength =
    		((MESSAGELENGTH + AES_BLOCK_SIZE)
    				/ AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char *encryptedMessage_first =
    		(unsigned char*)malloc(sizeof(unsigned char)
    				* encslength);
    unsigned char *encryptedMessage_second =
    		(unsigned char*)malloc(sizeof(unsigned char)
    				* encslength);
    int oracle=rand()%2;
    if(oracle==0)
    {
    	encryptedMessage_first=encMessage(message1,MESSAGELENGTH,iv);
    }
    else
    {
    	encryptedMessage_first=encMessage(message2,MESSAGELENGTH,iv);
    }
    for(int j=0;j<AES_BLOCK_SIZE;j++)
    {
    	message1[j]=message1[j]^iv[j];
    }
    if(oracle==0)
    {
    	encryptedMessage_second=encMessage(message1,MESSAGELENGTH,iv);
    }
    else
    {
    	encryptedMessage_second=encMessage(message2,MESSAGELENGTH,iv);
    }
    int result=strcmp((char*)encryptedMessage_first,(char*)encryptedMessage_second);
    if(result==0)
    	printf("First message was encrypted\n");
    else
    	printf("Second message was encrypted\n");

    printf("Oracle choise: %d\n", oracle);
    //hex_print(encryptedMessage, MESSAGELENGTH);

    /*
    unsigned char *aes_key =
    		(unsigned char*)malloc(sizeof(unsigned char)
    				* (KEYLENGTH/8));
    memset(aes_key, 0, KEYLENGTH/8);
    if (!RAND_bytes(aes_key, KEYLENGTH/8))
        exit(-1);
    size_t inputslength = 92;
    unsigned char *aes_input =
    		(unsigned char*)malloc(sizeof(unsigned char)
    				* inputslength);
    memset(aes_input, 'X', inputslength);
    // buffers for encryption and decryption
    const size_t encslength =
    		((inputslength + AES_BLOCK_SIZE)
    				/ AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char *enc_out =
    		(unsigned char*)malloc(sizeof(unsigned char)
    				* encslength);
    unsigned char *dec_out =
    		(unsigned char*)malloc(sizeof(unsigned char)
    				* inputslength);
    memset(enc_out, 0, sizeof(enc_out));
    memset(dec_out, 0, sizeof(dec_out));
    encMessage(aes_input,inputslength);

    // so i can do with this aes-cbc-128 aes-cbc-192 aes-cbc-256
    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(aes_key, KEYLENGTH, &enc_key);
    AES_cbc_encrypt(aes_input, enc_out, inputslength,
    		&enc_key, iv, AES_ENCRYPT);

    AES_set_decrypt_key(aes_key, KEYLENGTH, &dec_key);
    AES_cbc_encrypt(enc_out, dec_out, encslength,
    		&dec_key, iv_dec, AES_DECRYPT);

    printf("original:\t");
    hex_print(aes_input, inputslength);

    printf("encrypt:\t");
    hex_print(enc_out, encslength);

    printf("decrypt:\t");
    hex_print(dec_out, inputslength);

    // free memory here
*/
    return 0;
}
