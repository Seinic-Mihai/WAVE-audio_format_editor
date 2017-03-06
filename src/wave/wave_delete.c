#include "wave.h"
#include "project.h"

void	wave_delete(wave_t **wave)
{
	if (*wave != NULL && (*wave)->header != NULL)
	{
		free((*wave)->header);
		(*wave)->header = NULL;
	}
	if (*wave != NULL && (*wave)->data != NULL)
	{
		free((*wave)->data);
		(*wave)->data = NULL;
	}
	if (*wave != NULL)
	{
		free(*wave);
		*wave = NULL;
	}

}
