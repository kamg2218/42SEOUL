/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:02 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/31 00:17:22 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	charadd(char **str, char c)
{
	int		i;
	int		cnt;
	char	*result;

	i = 0;
	cnt = 0;
	while ((*str)[cnt])
		cnt++;
	result = (char *)malloc(sizeof(char) * ((cnt + 1) + 1));
	if (result == NULL)
		malloc_error();
	while (i < cnt)
	{
		result[i] = (*str)[i];
		i++;
	}
	result[i] = c;
	result[cnt + 1] = '\0';
	free(*str);
	*str = result;
	return ;
}

char	*search_env(char *key, t_var *env)
{
	t_var	*cur;
	char	*temp;
	char	*result;

	cur = env;
	while (cur)
	{
		if (!ft_strcmp(key, cur->key))
		{
			temp = cur->value;
			result = temp != NULL ? ft_strdup(temp) : ft_strdup("");
			if (!result)
				return (malloc_error());
			else
				return (result);
		}
		cur = cur->next;
	}
	return (ft_strdup(""));
}

char	*find_val(char *str, int *i, t_var *env)
{
	char	*val;
	char	*key;

	key = ft_strdup("");
	while (ft_isalnum(str[*i]) || str[*i] == '_')
	{
		charadd(&key, str[*i]);
		(*i)++;
	}
	val = search_env(key, env);
	free(key);
	return (val);
}

char	*convert_env(char *str, t_var *env)
{
	char	*result;
	char	*temp;
	int		i;
	char	*value;

	i = 0;
	result = ft_strdup("");
	while (str[i])
	{
		if (str[i] == (char)(-DOLLAR))
		{
			i++;
			temp = result;
			value = find_val(str, &i, env);
			result = ft_strjoin(result, value);
			free(temp);
			free(value);
		}
		else
		{
			charadd(&result, str[i]);
			i++;
		}
	}
	return (result);
}

char	*pos_env(char *str)
{
	int		i;
	int		len;
	char	bef;

	i = 0;
	bef = '\0';
	len = ft_strlen(str);
	while (i < len)
	{
		if (i >= len)
			break ;
		if (str[i] == '$' && bef != '\\')
		{
			if (i + 1 < len &&
					(str[i + 1] == '?' || str[i + 1] == '$'))
				i++;
			else
				return (str + i);
		}
		bef = (str[i] == '\\' && bef == '\\') ? '\0' : str[i];
		i++;
	}
	return (NULL);
}
