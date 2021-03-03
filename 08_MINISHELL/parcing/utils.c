/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 18:30:08 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 18:09:08 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

char	*ft_strldup(char *str, int start, int end)
{
	int		cnt;
	int		i;
	char	*result;

	i = 0;
	cnt = end - start + 1;
	if (!(result = (char *)malloc(sizeof(char) + (cnt + 1))))
		return (malloc_error());
	while (i < cnt)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	result[cnt] = '\0';
	return (result);
}

int		ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*malloc_error(void)
{
	g_mini.signal = 12;
	kill(0, SIGTERM);
	return (NULL);
}

int		syntax_error(char *cmd)
{
	ft_putstr_fd("minishell: ", g_mini.tmpout);
	ft_putstr_fd("syntax error ", g_mini.tmpout);
	ft_putstr_fd(cmd, g_mini.tmpout);
	ft_putstr_fd("\n", g_mini.tmpout);
	g_mini.signal = 258;
	return (1);
}

int		quote_error(char *input)
{
	int		i;
	int		quote;
	char	bef;

	i = 0;
	quote = 0;
	bef = '\0';
	while (input[i])
	{
		if (i + 2 < (int)ft_strlen(input) - 1 && input[i] == '>'
			&& input[i + 1] == '>' && input[i + 2] == '>')
			return (syntax_error("near unexpectd token \'>\'"));
		if (input[i] == '\\' && bef != '\\'
			&& i == (int)ft_strlen(input) - 1)
			return (syntax_error("unknown escape sequence \'\\ \'"));
		quote = is_quotes(input[i], bef, quote);
		bef = (input[i] == '\\' && bef == '\\') ? '\0' : input[i];
		i++;
	}
	if (quote)
		return (syntax_error("with open quote"));
	return (0);
}
