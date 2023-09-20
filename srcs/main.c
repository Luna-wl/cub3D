/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:50 by wluedara          #+#    #+#             */
/*   Updated: 2023/09/20 16:53:42 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
	{
		printf("Error cuz u put wrong num argument\n");
		return(0);
	}
	if (!check_file(av[1]))
		return (0);
	init_cub(&cub);
	verify_file(av[1], &cub);
}
