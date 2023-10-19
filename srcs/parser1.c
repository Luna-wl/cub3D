/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:55:57 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/19 14:49:59 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_file(char *s)
{
	char	*file;

	file = ft_strrchr(s, '.');
	if (ft_strncmp(file, ".cub", 5))
	{
		perror("Error\n wrong file name");
		return (0);
	}
	return (1);
}

int	check_row(char *s)
{
	char	*line;
	int		row;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		perror(RED"Error\nPoet mai dai!!! (ಥ﹏ಥ)\n"RESET);
	line = get_next_line(fd);
	row = 1;
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (row);
}

void	get_file(char *s, t_cub *cub)
{
	int		fd;
	int		i;
	int		row;
	char	**data;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		perror(RED"Error\nOpen mai dai!!! (ಥ﹏ಥ)\n");
	row = check_row(s);
	data = malloc(sizeof(char *) * (row + 1));
	if (!data)
		return ;
	i = 0;
	data[i] = get_next_line(fd);
	while (++i < row)
		data[i] = get_next_line(fd);
	close(fd);
	cub->file = insert2list(data, cub->file);
	del_2stars(data);
}

void	verify_file(char *file, t_cub *cub)
{
	get_file(file, cub);
	check_data(cub);
	// get_data(cub);
	// print_2stars(cub->map);
	// print_list(cub->file);
}
