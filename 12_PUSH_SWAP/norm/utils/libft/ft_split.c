/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:22:08 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/13 21:27:44 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int		i;
	int		to;
	int		from;
	int		count;

	i = 0;
	to = 0;
	from = 0;
	count = 0;
	while (s[to])
		to++;
	while (i <= to)
	{
		if ((s[i] == c || s[i] == '\0') && i - from > 0)
		{
			count++;
			from = i + 1;
		}
		else if (s[i] == c)
			from = i + 1;
		i++;
	}
	return (count);
}

static int		ft_col_count(char const *s, char c, int i)
{
	int		count;

	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (count);
		count++;
		i++;
	}
	return (count);
}

static void		ft_free(char **str, int d)
{
	int		i;

	i = -1;
	while (++i < d && str[i])
		free(str[i]);
}

static int		ft_fill(char const *s, char **str, char c)
{
	int		i;
	int		j;
	int		k;
	int		count;

	count = ft_count(s, c);
	i = 0;
	k = 0;
	while (k < count && s[i])
	{
		j = ft_col_count(s, c, i);
		if (j)
		{
			str[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (str[k] == NULL)
			{
				ft_free(str, k);
				return (0);
			}
			ft_memcpy(str[k], &s[i], j);
			str[k++][j] = 0;
		}
		i += j + 1;
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	if (!s)
		return (0);
	count = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (str == NULL)
		return (0);
	if (!ft_fill(s, str, c))
	{
		free(str);
		return (0);
	}
	str[count] = 0;
	return (str);
}
