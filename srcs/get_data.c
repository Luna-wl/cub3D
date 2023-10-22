/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:21:48 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/22 20:29:26 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

char	*get_pic(char **s, t_cub *cub, char *pic)
{
	if (!check_path(s[1]))
		error_false(cub, "Error\ncuz can not open path");
	pic = ft_strdup(s[1]);
	cub->value->c++;
	return (pic);
}

void	get_color(char **s, t_cub *cub)
{
	char	**c;
	int		r;
	int		g;
	int		b;

	c = ft_split(s[1], ',');
	r = ft_atoi(c[0]);
	g = ft_atoi(c[1]);
	b = ft_atoi(c[2]);
	if (check_num(s[1]) != 2 || !check_digit(c[0]) || !check_digit(c[1]) \
		|| !check_digit(c[2]) || r < 0 || r > 255 || g < 0 \
		|| g > 255 || b < 0 || b > 255)
	{
		del_2stars(s);
		error_false(cub, "Error\ncuz u put wrong num argument\n");
	}
	cub->value->c++;
	if (!ft_strncmp(s[0], "F", 2))
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

	tmp = cub->file;
	int_val(cub->value);
	while (tmp != NULL)
	{
		str = fah_split(tmp->file);
		if (!ft_strncmp(str[0], "NO", 3) && str[1])
			cub->north = get_pic(str, cub, cub->north);
		else if (!ft_strncmp(str[0], "SO", 3) && str[1])
			cub->south = get_pic(str, cub, cub->south);
		else if (!ft_strncmp(str[0], "WE", 3) && str[1])
			cub->west = get_pic(str, cub, cub->west);
		else if (!ft_strncmp(str[0], "EA", 3) && str[1])
			cub->east = get_pic(str, cub, cub->east);
		else if ((!ft_strncmp(str[0], "F", 2) || !ft_strncmp(str[0], "C", 2)) \
		&& str[1])
			get_color(str, cub);
		if (cub->value->c == 6)
			return (del_2stars(str), del_list2(cub, cub->value->n));
		tmp = tmp->next;
		del_2stars(str);
		cub->value->n++;
	}
}
