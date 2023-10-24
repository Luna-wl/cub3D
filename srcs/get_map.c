/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:57:12 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/23 02:21:55 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

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

int	check_wall(int x, int y, char **map)
{
	if ((map[y][x - 1] != '1' && map[y][x + 1] != '1' && map[y - 1][x] != '1' \
	&& map[y + 1][x] != '1') || (map[y][x - 1] != '0' && map[y][x + 1] != '0' && \
	map[y - 1][x] != '0' && map[y + 1][x] != '0'))
		return (0);
	return (1);
}

void	flood_fill(int x, int y, char **map, t_cub *cub)
{
	int	row;

	row = ft_strlen(map[y]) - 1;
	if (map == NULL)
		return ;
	if (x < 0 || y < 0 || y > cub->map->column || x > row || \
	map[y][x] == '1')
		return ;
	if (map[y][x] == '0')
	{
		if (check_wall(x, y, map) == 0)
		{
			printf("====\n");
			cub->value->error++;
		}
	}
	map[y][x] = '1';
	flood_fill(x - 1, y, map, cub);
	flood_fill(x, y - 1, map, cub);
	flood_fill(x + 1, y, map, cub);
	flood_fill(x, y + 1, map, cub);
}

void	check_map(t_cub *cub)
{
	t_map	new;

	po_start(cub->map, cub);
	new.x = cub->map->x;
	new.y = cub->map->y;
	new.map = fah_dup2stars(cub->map->map);
	// printf("new.x = %d\n",new.x);
	// printf("new.y = %d\n",new.y);
	// printf("new.column = %d\n",new.column);
	// printf("error = %d\n",cub->value->error);
	flood_fill(new.x, new.y, new.map, cub);
	print_2stars(new.map);
	del_2stars(new.map);
}

void	get_map(t_cub *cub)
{
	int		len;
	int		i;
	t_file	*tmp;

	len = find_len(cub->file);
	cub->map->column = len - 1;
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
