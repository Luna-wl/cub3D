/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:21:48 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/19 14:50:16 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

char	*get_pic(char **s, char *cub)
{
	if (s[2] != NULL)
	{
		printf("Error\n cuz u put wrong num argu in direction\n");
		exit(0);
	}
	cub = ft_strdup(s[1]);
	return (cub);
}

int	check_decimal(char *s)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (s[i] == ',')
			d++;
		i++;
	}
	return (d);
}

int	check_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	add_rgb(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	get_color(char **s, t_cub *cub, int mode)
{
	char	**c;
	int		r;
	int		g;
	int		b;

	c = ft_split(s[1], ',');
	r = ft_atoi(c[0]);
	g = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	if (check_decimal(s[1]) != 2 || !check_digit(c[0]) || !check_digit(c[1]) \
		|| !check_digit(c[2]) || s[2] != NULL || r < 0 || r > 255 || g < 0 \
		|| g > 255 || b < 0 || b > 255)
	{
		printf("Error\n cuz u put wrong num argument\n");
		exit(0);
	}
	if (mode == 1)
		add_rgb(cub->ceil, r, g, b);
	else
		add_rgb(cub->floor, r, g, b);
}

void	get_data(t_cub *cub)
{
	// t_file	*tmp;
	// int		i;
	(void)cub;
	// i = -1;
	// tmp = cub->file;
	// while (tmp != NULL)
	// {
	// 	if (!ft_strncmp(tmp->file, "NO", 3))
	// 	// else if (!ft_strncmp(cub->file->file, "SO", 3))
	// 	// else if (!ft_strncmp(cub->file->file, "WE", 3))
	// 	// else if (!ft_strncmp(cub->file->file, "EA", 3))
	// 	// else if (!ft_strncmp(cub->file->file, "F", 2))
	// 	// else if (!ft_strncmp(cub->file->file, "C", 2))
	// 	tmp = tmp->file;
	// }
	// del_3stars(data);
}
