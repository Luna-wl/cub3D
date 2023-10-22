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

typedef struct s_map {
	int		x;
	int		y;
	int		column;
	char	**map;
	char	direction;
}	t_map;

typedef struct s_cub {
	t_file		*file;
	t_value		*value;
	t_color		*ceil;
	t_color		*floor;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	// char		**map;
	t_map		*map;
} t_cub;

// init
void	init_cub(t_cub *cub);
void	int_val(t_value *value);
// parser1
int		check_file(char *s);
void	verify_file(char *file, t_cub *cub);
void	get_file(char *s, t_cub *cub);
//utils
void	print_2stars(char **s);
void	del_2stars(char **s);
char	*fah_strdup(char *s, char c);
char	**fah_dup2stars(char **str);
// utils 2
void	print_data(t_cub *cub);
int		check_null(char **s, int row);
int		is_space(char c);
void	print_list(t_file *file);
int		lenght_2star(char **s);
void	del1node(t_file **file);
// get_data
char	*get_pic(char **s, t_cub *cub, char *pic);
void	get_color(char **s, t_cub *cub);
void	del_list2(t_cub *cub, int i);
void	get_data(t_cub *cub);
// get_data
int		check_num(char *s);
int		check_digit(char *s);
void	add_rgb(t_color *color, int r, int g, int b);
// fah split
int		f_check_word(char *s);
int		f_count_letter(char *s);
char	*f_my_split(char *s);
char	**fah_split(char *s);
// error
void	error_false(t_cub *cub, char *s);
void	del_list(t_file **file);
void	free_everyth(t_cub *cub);
// addlist
t_file	*insert2list(char *str, t_file *file);
void	add_last(t_file **file, t_file *last);
// check data
int		check_path(char *s);
void	check_data2(t_cub *cub, char *str);
void	check_data(t_cub *cub);
//get_map
void	po_start(t_map *map, t_cub *cub);
void	flood_fill(int x, int y, char **map, t_cub *cub);
void	check_map(t_cub *cub);
void	get_map(t_cub *cub);
//get_map2
int		find_len(t_file *file);
char	*dup_map2(char *s, char *new, int num);
char	*dup_map(char *s);

#endif
