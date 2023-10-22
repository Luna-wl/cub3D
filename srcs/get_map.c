/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:57:12 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/22 20:10:45 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	find_len(t_file *file)
{
	t_file	*tmp;
	int		len;

	tmp = file;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	po_start(t_map *map, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (is_space(map->map[i][j]))
				j++;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0' && \
			map->map[i][j] != 'N' && map->map[i][j] != 'S' && map->map[i][j] \
			!= 'W' && map->map[i][j] != 'E')
				error_false(cub, "This is not a map.");
			else if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || \
			map->map[i][j] == 'W' || map->map[i][j] == 'E')
			{
				map->direction = map->map[i][j];
				map->x = j;
				map->y = i;
				return ;
			}
		}
	}
}

void	flood_fill(int x, int y, int column, char **map)
{
	int	row;

	row = ft_strlen(map[y]) - 1;
	// printf("y = %d\n", y);
	// printf("row = %d\n", row);
	if (map == NULL)
		return ;
	if (x < 0 || y < 0 || y > column || x > row)
		return ;
	if (is_space(map[y][x]))
		map[y][x] = '2';
	map[y][x] = '1';
	// print_2stars(map);
	// exit(0);
	flood_fill(x - 1, y, column, map);
	flood_fill(x, y - 1, column, map);
	flood_fill(x + 1, y, column, map);
	flood_fill(x, y + 1, column, map);
}

void	check_map(t_cub *cub)
{
	t_map	new;

	print_2stars(cub->map->map);
	po_start(cub->map, cub);
	new.x = cub->map->x;
	new.y = cub->map->y;
	new.column = cub->map->column;
	new.map = fah_dup2stars(cub->map->map);
	// printf("new.x = %d\n",new.x);
	// printf("new.y = %d\n",new.y);
	// printf("new.column = %d\n",new.column);
	// printf("error = %d\n",cub->value->error);
	// for (int i = 0; i < ft_strlen(new.map[0]); i++)
	// {
	// 	printf("c[%i] = %c\n", i, new.map[0][i]);
	// }
	// flood_fill(new.x, new.y, new.column, new.map, cub->value->error);
	del_2stars(new.map);
}

char	*dup_map2(char *s, char *new, int num)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (len < num)
	{
		if (s[i] == '\t')
		{
			new[len] = ' ';
			new[len + 1] = ' ';
			new[len + 2] = ' ';
			new[len + 3] = ' ';
			len += 4;
		}
		else
		{
			new[len] = s[i];
			len++;
		}
		i++;
	}
	new[len] = '\0';
	return (new);
}

char	*dup_map(char *s)
{
	int		i;
	int		len;
	int		num;
	char	*new;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '\t')
			len++;
	}
	num = (ft_strlen(s) - len) + (len * 4);
	new = malloc(num + 1);
	if (!new)
		return (0);
	return (dup_map2(s, new, num));
}

void	get_map(t_cub *cub)
{
	int		len;
	int		i;
	t_file	*tmp;

	len = find_len(cub->file);
	cub->map->column = len;
	cub->map->map = malloc(sizeof(char *) * (len + 1));
	if (!cub->map->map)
		return ;
	tmp = cub->file;
	i = 0;
	while (tmp != NULL)
	{
		cub->map->map[i] = dup_map(tmp->file);
		tmp = tmp->next;
		i++;
	}
	cub->map->map[i] = NULL;
	check_map(cub);
}
