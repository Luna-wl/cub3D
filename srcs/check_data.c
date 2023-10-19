/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:06:57 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/20 00:20:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_path(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	check_data2(t_cub *cub, char *str)
{
	char	**s;

	s = fah_split(str);
	if (ft_strncmp(s[0], "NO", 3) && ft_strncmp(s[0], "SO", 3) && \
	ft_strncmp(s[0], "WE", 3) && ft_strncmp(s[0], "EA", 3) && \
	ft_strncmp(s[0], "F", 2) && ft_strncmp(s[0], "C", 2) && s[0][0] != '1' \
	&& s[0][0] != '0')
		cub->value->error++;
	if (s[0] && !ft_strncmp(s[0], "NO", 3) && s[1] && lenght_2star(s) == 2)
		cub->value->n++;
	else if (s[0] && !ft_strncmp(s[0], "SO", 3) && s[1] && lenght_2star(s) == 2)
		cub->value->s++;
	else if (s[0] && !ft_strncmp(s[0], "WE", 3) && s[1] && lenght_2star(s) == 2)
		cub->value->w++;
	else if (s[0] && !ft_strncmp(s[0], "EA", 3) && s[1] && lenght_2star(s) == 2)
		cub->value->e++;
	else if (s[0] && !ft_strncmp(s[0], "F", 2) && s[1] && lenght_2star(s) == 2)
		cub->value->f++;
	else if (s[0] && !ft_strncmp(s[0], "C", 2) && s[1] && lenght_2star(s) == 2)
		cub->value->c++;
	del_2stars(s);
}

void	check_data(t_cub *cub)
{
	t_file	*tmp;

	tmp = cub->file;
	while (tmp != NULL)
	{
		if (tmp->file[0] != '\0')
			check_data2(cub, tmp->file);
		tmp = tmp->next;
	}
	if (cub->value->n != 1 || cub->value->s != 1 || cub->value->w != 1 || \
	cub->value->e != 1 || cub->value->c != 1 || cub->value->f != 1 || \
	cub->value->error > 0)
		error_false(cub, "Data in file is not correct");
}
