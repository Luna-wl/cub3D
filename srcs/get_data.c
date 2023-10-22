/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:21:48 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/22 15:48:15 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

char	*get_pic(char *s, t_cub *cub, char *pic)
{
	if (!check_path(s))
		error_false(cub, "Error\ncuz can not open path");
	pic = ft_strdup(s);
	cub->value->c++;
	return (pic);
}

int	check_num(char *s)
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

void	get_color(char *s, t_cub *cub, int mode)
{
	char	**c;
	int		r;
	int		g;
	int		b;

	c = ft_split(s, ',');
	r = ft_atoi(c[0]);
	g = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	if (check_num(s) != 2 || !check_digit(c[0]) || !check_digit(c[1]) \
		|| !check_digit(c[2]) || r < 0 || r > 255 || g < 0 \
		|| g > 255 || b < 0 || b > 255)
	{
		printf("Error\n cuz u put wrong num argument\n");
		exit(0);
	}
	cub->value->c++;
	if (mode == 1)
		add_rgb(cub->ceil, r, g, b);
	else
		add_rgb(cub->floor, r, g, b);
}

void	del_list2(t_cub *cub, int i)
{
	int		len;
	int		j;
	char	**str;
	t_file	*tmp;

	tmp = cub->file;
	len = i;
	while (len >= 0)
	{
		str = fah_split(tmp->file);
		if (str[0][0] == '1' || str[0][0] == '0')
		{
			del_2stars(str);
			error_false(cub, "Something is not right in the file.");
		}
		del_2stars(str);
		tmp = tmp->next;
		len--;
	}
	j = 0;
	while (j <= i)
	{
		del1node(&cub->file);
		j++;
	}
}

void	get_data(t_cub *cub)
{
	t_file		*tmp;
	char		**str;
	static int	i = 0;

	tmp = cub->file;
	int_val(cub->value);
	while (tmp != NULL)
	{
		str = fah_split(tmp->file);
		if (!ft_strncmp(str[0], "NO", 3) && str[1])
			cub->north = get_pic(str[1], cub, cub->north);
		else if (!ft_strncmp(str[0], "SO", 3) && str[1])
			cub->south = get_pic(str[1], cub, cub->south);
		else if (!ft_strncmp(str[0], "WE", 3) && str[1])
			cub->west = get_pic(str[1], cub, cub->west);
		else if (!ft_strncmp(str[0], "EA", 3) && str[1])
			cub->east = get_pic(str[1], cub, cub->east);
		else if (!ft_strncmp(str[0], "F", 2) && str[1])
			get_color(str[1], cub, 0);
		else if (!ft_strncmp(str[0], "C", 2) && str[1])
			get_color(str[1], cub, 1);
		if (cub->value->c == 6)
			return (del_2stars(str), del_list2(cub, i));
		del_2stars(str);
		tmp = tmp->next;
		i++;
	}

}
