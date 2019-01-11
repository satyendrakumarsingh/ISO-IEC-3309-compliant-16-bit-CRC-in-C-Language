#include<stdio.h>
    unsigned short crcCalculator(const unsigned char* data_p, unsigned char length){
        unsigned char x;
        unsigned short crc = 0xFFFF;

        while(length--) {
            x = crc >> 8 ^ *data_p++;
            x ^= x>>4;
            crc = (crc << 8) ^ ((unsigned short)(x << 12)) ^ ((unsigned short)(x <<5)) ^ ((unsigned short)x);
        }
        
        return crc;
    }
    /* MAIN METHOD FOR TESTING PURPOSE */    
    int main() {
	unsigned char plainTextData[] = "20101021202164403849800004306041552202409800";
	printf("%X", crcCalculator(plainTextData, sizeof(plainTextData)-1));
    }
