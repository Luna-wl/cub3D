/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:44:31 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/15 21:30:55 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_data(char **data, t_cub *cub, int r)
{
	get_map(data, cub, r);
}

void	error_false(t_cub *cub, char *s)
{
	printf(RED"%s\n"RESET, s);
	if (cub->data)
		del_3stars(cub->data);
	if (cub->map)
		del_2stars(cub->map);
	if (cub->north)
		free(cub->north);
	if (cub->south)
		free(cub->south);
	if (cub->west)
		free(cub->west);
	if (cub->east)
		free(cub->east);
	if (cub->ceil)
		free(cub->ceil);
	if (cub->floor)
		free(cub->floor);
	exit(0);
}
