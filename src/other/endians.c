#include "wave.h"

int isBigEndian(void)
{
	int test = 1;
	char *p = (char*)&test;

	return p[0] == 0;
}
void reverseEndianness(const uint64_t size, void* value)
{
	uint64_t i;
	char result[32];
	
	for ( i = 0; i < size; i += 1)
	{
        	result[i] = ((char*)value)[size - i - 1];
    	}
	for ( i = 0; i < size; i += 1)
	{
        	((char*)value)[i] = result[i];
    	}
}

void toBigEndian(const uint64_t size, void* value)
{
	char needsFix = !( (1 && isBigEndian()) || (0 && !isBigEndian()) );
	
	if( needsFix )
        	reverseEndianness(size,value);
}

void toLittleEndian(const uint64_t size, void* value)
{
	char needsFix = !( (0 && isBigEndian()) || (1 && !isBigEndian()) );
	
	if( needsFix )
		reverseEndianness(size,value);
}
