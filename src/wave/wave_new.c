#include "wave.h"

static wave_header     *make_wave_header(uint32_t const f, uint16_t const c, uint16_t const p, uint32_t const B)
{
        wave_header     *new_wave_header;
	uint16_t	align;
	uint32_t	rate;
	uint64_t	data_size;
	
	align = c * (p / 8);
	rate = f * align;
	data_size = B * align;
	new_wave_header = (wave_header *)malloc(HEADER_SIZE);
	strncpy(new_wave_header->riff, "RIFF", 4);
	strncpy(new_wave_header->wave, "WAVE", 4);
	strncpy(new_wave_header->fmt_str, "fmt ", 4);
	strncpy(new_wave_header->data, "data", 4);

        new_wave_header->fmt_type = 1;
        new_wave_header->channels = c;
        new_wave_header->sample_rate = f;
        new_wave_header->bits_per_sample = p;
        new_wave_header->byterate = rate;
        new_wave_header->block_align = align;
    
        new_wave_header->fmt_length = 16;
        new_wave_header->data_size = data_size; 
        new_wave_header->overall_size = data_size + HEADER_SIZE - 8;
        return (new_wave_header);
}

wave_t *wave_new(uint32_t f, uint16_t p, uint16_t c, uint32_t B)
{
	wave_t		*wave;

	wave = (wave_t *)malloc(sizeof(wave_t));
	wave->header = make_wave_header(f, c, p, B);
	wave->data = (char *)malloc(sizeof(char) * ((B * c * (p / 8)) + 1));
	return (wave);
}
