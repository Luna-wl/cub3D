/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:09:05 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/21 15:01:45 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	check_null(char **s, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && i < row)
	{
		if (is_space(s[i][0]) || s[i][0] == '#')
			j++;
		i++;
	}
	return (i - j);
}

void	print_list(t_file *file)
{
	t_file	*tmp;

	tmp = file;
	while (tmp != NULL)
	{
		printf("tmp->file[%d] = %s\n", tmp->index, tmp->file);
		tmp = tmp->next;
	}
}

int	lenght_2star(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	del1node(t_file **file)
{
	t_file	*tmp;

	if (*file == NULL)
		return ;
	tmp = *file;
	*file = tmp->next;
	free(tmp->file);
	free(tmp);
}
