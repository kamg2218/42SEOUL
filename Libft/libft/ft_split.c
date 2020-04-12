/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:22:08 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/12 23:13:14 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

static void		ft_strncpy(char const *s, char *str, int i, int n)
{
	int		k;

	k = -1;
	while (++k < n)
		str[k] = s[i + k];
	str[k] = 0;
}

static void		ft_fill(char const *s, char **str, char c)
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
				free(str);
				return ;
			}
			ft_strncpy(s, str[k], i, j);
			k++;
		}
		i += j + 1;
	}
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
	ft_fill(s, str, c);
	str[count] = (char *)malloc(sizeof(char));
	if (str[count] == NULL)
	{
		free(str);
		return (0);
	}
	str[count] = 0;
	return (str);
}
