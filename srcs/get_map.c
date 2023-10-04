/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:57:12 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/04 22:03:05 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	printfmap(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		printf("s[%d] = %s\n", i, s[i]);
		i++;
	}
}

void	add2map(char **map, char **data, int i, int r)
{
	int	j;

	j = 0;
	while (j < r)
		map[j++] = fah_strdup(data[i++], '\n');
	map[j] = NULL;
}

void	get_map(char **data, t_cub *cub, int r)
{
	int i;

	i = 0;
	while (i < r - 1)
	{
		if (data[i][0] == 'N' || data[i][0] == 'S' || \
		data[i][0] == 'W' || data[i][0] == 'E' || data[i][0] == 'F' || \
		data[i][0] == 'C' || data[i][0] == '\n')
			i++;
		else
			break;
	}
	cub->map = malloc(sizeof(char *) * (r - i));
	add2map(cub->map, data, i, r - i - 1);
}