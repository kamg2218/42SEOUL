/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:45:11 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/13 12:19:49 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *split, char *str, int from, int to)
{
	int		i;

	i = 0;
	while (i < to - from)
	{
		split[i] = str[from + i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

int		ft_strcmp(char *str, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (*str == charset[i])
			return (1);
		else
			i++;
	}
	return (0);
}

void	ft_fill(char **split, char *str, char *charset, int count)
{
	int		i;
	int		to;
	int		from;

	i = 0;
	to = 0;
	while (i < count)
	{
		from = to;
		while (!ft_strcmp(&str[to], charset) && str[to] != '\0')
			to++;
		if (to - from != 0)
		{
			split[i] = (char *)malloc(sizeof(char) * (to - from + 1));
			if (split[i] == NULL)
				return ;
			ft_strncat(split[i], str, from, to);
			i++;
		}
		to++;
	}
	split[i] = malloc(1);
	if (split[i] == NULL)
		return ;
	split[i][0] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		to;
	int		count;
	char	**split;

	to = 1;
	count = 1;
	while (str[to])
	{
		if (ft_strcmp(&str[to], charset)
				&& !ft_strcmp(&str[to - 1], charset))
			count++;
		to++;
	}
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if ((*split) == NULL)
		return (0);
	ft_fill(split, str, charset, count);
	return (split);
}
