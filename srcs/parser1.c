/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:55:57 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/22 20:36:17 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_file(char *s)
{
	char	*file;

	file = ft_strchr(s, '.');
	if (ft_strncmp(file, ".cub", 5))
	{
		perror("Error\nwrong file name");
		return (0);
	}
	return (1);
}

void	get_file(char *s, t_cub *cub)
{
	int		fd;
	char	*line;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		perror(RED"Error\nOpen mai dai!!! (ಥ﹏ಥ)\n");
	line = get_next_line(fd);
	while (line)
	{
		cub->file = insert2list(line, cub->file);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	verify_file(char *file, t_cub *cub)
{
	get_file(file, cub);
	check_data(cub);
	get_data(cub);
	get_map(cub);
	// print_data(cub);
}
