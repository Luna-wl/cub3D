/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:33:09 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/22 20:34:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	find_len(t_file *file)
{
	t_file	*tmp;
	int		len;

	tmp = file;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

char	*dup_map2(char *s, char *new, int num)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (len < num)
	{
		if (s[i] == '\t')
		{
			new[len] = ' ';
			new[len + 1] = ' ';
			new[len + 2] = ' ';
			new[len + 3] = ' ';
			len += 4;
		}
		else
		{
			new[len] = s[i];
			len++;
		}
		i++;
	}
	new[len] = '\0';
	return (new);
}

char	*dup_map(char *s)
{
	int		i;
	int		len;
	int		num;
	char	*new;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '\t')
			len++;
	}
	num = (ft_strlen(s) - len) + (len * 4);
	new = malloc(num + 1);
	if (!new)
		return (0);
	return (dup_map2(s, new, num));
}
