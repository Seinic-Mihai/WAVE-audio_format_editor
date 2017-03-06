#include "wave.h"

void add_signal(wave_t *wave, double (*s)(double)){
	double k = 0;
	uint32_t i;
	uint16_t j;
	for(i = 0; i < (W_DATA_SIZE(wave)/W_BLOCK_ALIGN(wave)); i++){
		k++;
		for(j = 0; j < W_CHANNELS(wave); j++){
			switch(W_BITS_PER_SAMPLE(wave)){
				case(8):wave_set(wave,i,j,(int64_t)((127.0)*(s(k))));break;
				case(16):wave_set(wave,i,j,(int64_t)((32767.0)*(s(k))));break;
				case(24):wave_set(wave,i,j,(int64_t)((8388607.0)*(s(k))));break;
				default : printf("Error\n"); break;
			}
		}
	}
}
