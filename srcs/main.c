/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:50 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/18 14:59:01 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_everyth(t_cub *cub)
{
	del_list(&cub->file);
	free(cub->value);
	if (cub->data)
		del_3stars(cub->data);
	if (cub->north)
		free(cub->north);
	if (cub->south)
		free(cub->south);
	if (cub->west)
		free(cub->west);
	if (cub->east)
		free(cub->east);
	if (cub->map)
		del_2stars(cub->map);
	free(cub->ceil);
	free(cub->floor);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
	{
		printf("Error\n cuz u put wrong num argument\n");
		return(0);
	}
	if (!check_file(av[1]))
		return (0);
	init_cub(&cub);
	verify_file(av[1], &cub);
	free_everyth(&cub);
}
