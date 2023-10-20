/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:42:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/21 01:27:33 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	add_last(t_file **file, t_file *last)
{
	t_file	*tmp;

	if (*file == NULL)
	{
		*file = last;
		return ;
	}
	tmp = *file;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = last;
}

t_file	*insert2list(char *str, t_file *file)
{
	t_file		*hua;
	static int	i = 0;

	if (str[0] == '\n')
		i--;
	if (str[0] != '\n')
	{
		hua = malloc(sizeof(t_file));
		hua->file = fah_strdup(str, '\n');
		hua->index = i;
		hua->next = NULL;
		add_last(&file, hua);
	}
	i++;
	return (file);
}
