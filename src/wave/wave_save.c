#include "wave.h"

bool	wave_save(const char* fname, wave_t *w)
{
	FILE	*ptr;

	if (!fname)
	{
		fprintf(stderr, "Filename not specified\n");
		return (false);
	}
	if (!(ptr = fopen(fname, "w")))
	{
		fprintf(stderr, "Error in opening the file\n");
		return (false);
	}
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->overall_size));
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->fmt_length));
	toLittleEndian(sizeof(uint16_t), (void*)&(w->header->fmt_type));
	toLittleEndian(sizeof(uint16_t), (void*)&(w->header->channels));
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->sample_rate));
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->byterate));
	toLittleEndian(sizeof(uint16_t), (void*)&(w->header->block_align));
	toLittleEndian(sizeof(uint16_t), (void*)&(w->header->bits_per_sample));
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->data_size));
	
	fwrite( w->header, sizeof(wave_header), 1, ptr );
	fwrite( (void*)(w->data), sizeof(char), W_DATA_SIZE(w), ptr );
	fclose( ptr );

	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->overall_size));
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->fmt_length));
	toLittleEndian(sizeof(uint16_t), (void*)&(w->header->fmt_type));
	toLittleEndian(sizeof(uint16_t), (void*)&(w->header->channels));
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->sample_rate));
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->byterate));
	toLittleEndian(sizeof(uint16_t), (void*)&(w->header->block_align));
	toLittleEndian(sizeof(uint16_t), (void*)&(w->header->bits_per_sample));
	toLittleEndian(sizeof(uint32_t), (void*)&(w->header->data_size));
	
	return (true);
}
