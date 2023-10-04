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
# include "../libft/get_next_line_bonus.h"

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_cub {
	char		***data;
	t_color		*ceil;
	t_color		*floor;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		**map;
} t_cub;

void	init_cub(t_cub *cub);
// verify
int		check_file(char *s);
void	verify_file(char *file, t_cub *cub);
void	get_file(char *s, t_cub *cub);
int		check_row(char *s);
//utils
void	print_2stars(char **s);
void	print_3stars(char ***s);
void	del_2stars(char **s);
void	del_3stars(char ***s);
char	*fah_strdup(char *s, char c);
// utils 2
char	***to3stars(char **s, char ***data, int row);
int		check_null(char **s, int row);
int		is_space(char c);
// get_data
void	get_data(char ***data, t_cub *cub);
char	*get_pic(char **s, char *cub);
// color
int		color_to_int(int r, int g, int b);
// fah split
int		f_check_word(char *s);
int		f_count_letter(char *s);
char	*f_my_split(char *s);
char	**fah_split(char *s);
// map
void	get_map(char **data, t_cub *cub, int r);

#endif
