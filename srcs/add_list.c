/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:42:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/20 00:14:51 by wluedara         ###   ########.fr       */
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

void	init_list(t_file **file, char *s)
{
	t_file	*hua;

	hua = malloc(sizeof(t_file));
	hua->file = fah_strdup(s, '\n');
	hua->next = NULL;
	add_last(file, hua);
}

t_file	*insert2list(char *str, t_file *file)
{
	if (str[0] != '\n')
		init_list(&file, str);
	return (file);
}

// t_file	*insert2list(char **str, t_file *file)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i][0] != '\n')
// 			init_list(&file, str[i]);
// 		i++;
// 	}
// 	return (file);
// }
