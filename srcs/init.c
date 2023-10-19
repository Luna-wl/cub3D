/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:50:53 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/20 00:16:55 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	int_val(t_value *value)
{
	value->n = 0;
	value->s = 0;
	value->w = 0;
	value->e = 0;
	value->c = 0;
	value->f = 0;
	value->error = 0;
}

void	init_cub(t_cub *cub)
{
	cub->file = NULL;
	cub->value = malloc(sizeof(t_value));
	int_val(cub->value);
	cub->north = NULL;
	cub->south = NULL;
	cub->west = NULL;
	cub->east = NULL;
	cub->map = NULL;
	cub->ceil = malloc(sizeof(t_color));
	cub->floor = malloc(sizeof(t_color));
}
