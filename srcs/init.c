/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:50:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/04 16:39:32 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	init_cub(t_cub *cub)
{
	cub->data = NULL;
	cub->north = NULL;
	cub->south = NULL;
	cub->west = NULL;
	cub->east = NULL;
	cub->map = NULL;
	cub->ceil = malloc(sizeof(t_color));
	cub->floor = malloc(sizeof(t_color));
}
