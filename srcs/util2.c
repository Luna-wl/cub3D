/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:09:05 by wluedara          #+#    #+#             */
/*   Updated: 2023/09/24 14:04:48 by wluedara         ###   ########.fr       */
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

char	***to3stars(char **s, char ***data, int row)
{
	int	i;
	int	j;
	int	row2;

	i = 0;
	j = 0;
	row2 = check_null(s, row);
	data = malloc(sizeof(char **) * (row2 + 1));
	if (!data)
		return (0);
	while (s[i] && i <= row)
	{
		if (is_space(s[i][0]) || s[i][0] == '#')
			i++;
		else
			data[j++] = fah_split(s[i++]);
	}
	data[j] = NULL;
	return (data);
}
