/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fah_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:46:25 by wluedara          #+#    #+#             */
/*   Updated: 2023/09/22 16:46:49 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	f_check_word(char *s)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (!is_space(s[i]) && s[i])
		{
			while (!is_space(s[i]) && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

int	f_count_letter(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && !is_space(s[i]))
	{
		if (!is_space(s[i]))
			i++;
	}
	return (i);
}

char	*f_my_split(char *s)
{
	char	*str;
	int		letter;
	int		i;
	int		j;

	letter = f_count_letter(s);
	str = (char *)malloc(sizeof(char) * (letter + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[j] != 0 && !is_space(s[j]))
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}

char	**fah_split(char *s)
{
	char	**new;
	int		word;
	int		i;
	int		j;

	i = 0;
	word = f_check_word(s);
	new = (char **)malloc(sizeof(char *) * (word + 1));
	if (!new)
		return (0);
	j = 0;
	while (i < word)
	{
		while (is_space(s[j]) && s[j] != '\0')
			j++;
		new[i++] = f_my_split(&s[j]);
		j += f_count_letter(&s[j]);
	}
	new[i] = 0;
	return (new);
}
