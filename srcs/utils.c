/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:38:44 by wluedara          #+#    #+#             */
/*   Updated: 2023/09/24 15:28:27 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	print_2stars(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		printf("s[%d] = %s\n", i, s[i]);
		i++;
	}
}

void	print_3stars(char ***s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		printf("==== i = |%d| =====\n", i);
		j = 0;
		while (s[i][j] != NULL)
		{
			printf("s[%d] = |%s|\n", j, s[i][j]);
			j++;
		}
		i++;
	}
}

void	del_2stars(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
}

void	del_3stars(char ***s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != NULL)
		{
			free(s[i][j]);
			j++;
		}
		i++;
	}
}

char	*fah_strdup(char *s, char c)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s) - 1;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		if (str[i] != c)
			str[i] = s[i];
		i++;
	}
	return (str);
}