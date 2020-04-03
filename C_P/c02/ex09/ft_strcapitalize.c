/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:55:03 by hyoon             #+#    #+#             */
/*   Updated: 2020/01/31 09:55:10 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_nonalpha(char *str)
{
	if (*str < 48)
		return (1);
	else if (*str > 57 && *str < 65)
		return (1);
	else if (*str > 90 && *str < 97)
		return (1);
	else if (*str > 122)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i])
	{
		i++;
		if (ft_str_is_nonalpha(&str[i - 1])
				&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		else if (ft_str_is_nonalpha(&str[i - 1]) == 0
				&& (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] += 32;
	}
	return (str);
}
