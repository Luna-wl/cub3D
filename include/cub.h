#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "color.h"
# include "../libft/libft.h"

typedef struct s_cub {
	int			ceil;
	int			floor;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		**map;
} t_cub;

int		check_file(char *s);
void	verify_file(char *file, t_cub *cub);
void	init_cub(t_cub *cub);

#endif
