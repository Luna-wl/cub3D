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

typedef struct s_file {
	char			*file;
	int				index;
	struct s_file	*next;
}	t_file;

typedef struct s_value {
	int	n;
	int	s;
	int	e;
	int	w;
	int	c;
	int	f;
	int	error;
}	t_value;

typedef struct s_cub {
	t_file		*file;
	t_value		*value;
	t_color		*ceil;
	t_color		*floor;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		**map;
} t_cub;

void	init_cub(t_cub *cub);
// parser1
int		check_file(char *s);
void	verify_file(char *file, t_cub *cub);
void	get_file(char *s, t_cub *cub);
//utils
void	print_2stars(char **s);
void	del_2stars(char **s);
char	*fah_strdup(char *s, char c);
// utils 2
void	print_data(t_cub *cub);
int		check_null(char **s, int row);
int		is_space(char c);
void	print_list(t_file *file);
int		lenght_2star(char **s);
void	del1node(t_file **file);
// get_data
void	get_data(t_cub *cub);
char	*get_pic(char *s, t_cub *cub, char *pic);
// fah split
int		f_check_word(char *s);
int		f_count_letter(char *s);
char	*f_my_split(char *s);
char	**fah_split(char *s);
// map
// void	get_map(char **str);
// error
void	error_false(t_cub *cub, char *s);
void	del_list(t_file **file);
void	free_everyth(t_cub *cub);
// addlist
t_file	*insert2list(char *str, t_file *file);
void	add_last(t_file **file, t_file *last);
// check data
void	check_data(t_cub *cub);
int		check_path(char *s);
void	get_color(char *s, t_cub *cub, int mode);
void	check_data2(t_cub *cub, char *str);

#endif
