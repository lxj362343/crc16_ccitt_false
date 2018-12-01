#include "stdio.h"

typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;

 uint16_t crc16_compute(uint8_t const * p_data, uint32_t size, uint16_t const * p_crc);
 
int main() 
{
	uint8_t i,n;
	uint8_t data[]={0x00,0X21,0X01,0X01,0X10,0X27,0x87,0xba};
	n = sizeof(data)/sizeof(uint8_t);
	uint16_t  c;	
	c = crc16_compute(data,n,NULL);
	printf("%x\n",c);	
	
	for(i=0;i<6;i++)
	{
		printf("%x\n",data[i]);
	 } 
	
}


 uint16_t crc16_compute(uint8_t const * p_data, uint32_t size, uint16_t const * p_crc)
{
	uint16_t crc = (p_crc == NULL) ? 0xFFFF : *p_crc;
	for (uint32_t i = 0; i < size; i++)
	{
		crc   = (uint8_t)(crc >> 8) | (crc << 8);
		crc ^= p_data[i];
		crc ^= (uint8_t)(crc & 0xFF) >> 4;
		crc ^= (crc << 8) << 4;
		crc ^= ((crc & 0xFF) << 4) << 1;
	}
	return crc;
}
