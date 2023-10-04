/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:21:48 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/04 16:40:02 by wluedara         ###   ########.fr       */
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

void	get_data(char ***data, t_cub *cub)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		if (!ft_strncmp(data[i][0], "NO", 3))
			cub->north = get_pic(data[i], cub->north);
		else if (!ft_strncmp(data[i][0], "SO", 3))
			cub->south = get_pic(data[i], cub->south);
		else if (!ft_strncmp(data[i][0], "WE", 3))
			cub->west = get_pic(data[i], cub->west);
		else if (!ft_strncmp(data[i][0], "EA", 3))
			cub->east = get_pic(data[i], cub->east);
		else if (!ft_strncmp(data[i][0], "F", 2))
			get_color(data[i], cub, 1);
		else if (!ft_strncmp(data[i][0], "C", 2))
			get_color(data[i], cub, 2);
	}
	del_3stars(data);
}