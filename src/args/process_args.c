#include "args.h"

void	process_arguments(option_t *l, int argc, char **argv){
	int		i;
	unsigned int	n2;
	unsigned int	n3;
	double          n1;
	list		cursor;

	printf("Executing functions:\n");
	i = 0;
	while (++i < argc)
	{
		cursor = l;
		while (cursor != NULL)
		{
			if (strcmp(cursor->keyword, argv[i]) == 0)
			{
				switch (cursor->spec)
				{
					case OptVoid: cursor->fct.opt_void();
						      break;
					case OptString: cursor->fct.opt_str(argv[i+1]);
							i++;
							break;
					case OptDouble: n1 = (double) atof(argv[i+1]);
							cursor->fct.opt_d(n1);
							i++;
							break;
					case OptUI: n2 = (unsigned int) atoi(argv[i+1]);
						    n3 = (unsigned int) atoi(argv[i+2]);
						    cursor->fct.opt_ui(n2,n3);
						    i += 2;
						    break;
					default: printf("Arg not found\n");
						 break;
				}
			}
			cursor = cursor->next;
		}
	}
}
