/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:38:44 by wluedara          #+#    #+#             */
/*   Updated: 2023/10/20 14:43:46 by wluedara         ###   ########.fr       */
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

void	del_2stars(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	if (s)
		free(s);
}

char	*fah_strdup(char *s, char c)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = malloc(len);
	if (!str)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		if (s[i] != c)
			str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	print_data(t_cub *cub)
{
	printf("north = %s\n", cub->north);
	printf("south = %s\n", cub->south);
	printf("west = %s\n", cub->west);
	printf("east = %s\n", cub->east);
	printf("floor->r = %d\n", cub->floor->r);
	printf("floor->g = %d\n", cub->floor->g);
	printf("floor->b = %d\n", cub->floor->b);
	printf("ceil->r = %d\n", cub->ceil->r);
	printf("ceil->g = %d\n", cub->ceil->g);
	printf("ceil->b = %d\n", cub->ceil->b);
}
