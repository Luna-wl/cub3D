/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:44:31 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/22 20:30:27 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_everyth(t_cub *cub)
{
	del_list(&cub->file);
	free(cub->value);
	if (cub->north)
		free(cub->north);
	if (cub->south)
		free(cub->south);
	if (cub->west)
		free(cub->west);
	if (cub->east)
		free(cub->east);
	if (cub->map)
	{
		del_2stars(cub->map->map);
		free(cub->map);
	}
	free(cub->ceil);
	free(cub->floor);
}

void	del_list(t_file **file)
{
	t_file	*tmp;
	t_file	*del;

	if (!file)
		return ;
	del = *file;
	while (del != NULL)
	{
		tmp = del->next;
		if (del->file != NULL)
			free(del->file);
		free(del);
		del = tmp;
	}
	*file = NULL;
}

void	error_false(t_cub *cub, char *s)
{
	printf(RED"%s\n"RESET, s);
	free_everyth(cub);
	exit(0);
}
