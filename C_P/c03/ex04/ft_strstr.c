/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:54:33 by hyoon             #+#    #+#             */
/*   Updated: 2020/02/04 15:33:12 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
		else if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

int		ft_strlen(char *s)
{
	int		i;

	if (s[0] == '\0')
		return (0);
	i = 1;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	if (ft_strlen(to_find) == 0)
		return (str);
	i = 0;
	while (i <= ft_strlen(str) - ft_strlen(to_find))
	{
		if (ft_strncmp(str + i, to_find, ft_strlen(to_find)) == 0)
			return (str + i);
		else
			i++;
	}
	return (0);
}
