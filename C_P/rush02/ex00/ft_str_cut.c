/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokang <dokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:59:22 by dokang            #+#    #+#             */
/*   Updated: 2020/02/09 23:30:16 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function_total.h"

char	**ft_str_memory(int length, int *digit, int *one_digit)
{
	char	**numbers;
	int		index;

	index = 0;
	*digit = (length - 1) / 3;
	*one_digit = length % 3;
	numbers = (char **)malloc(sizeof(char *) * (*digit + 3));
	while (index < *digit + 3)
	{
		numbers[index] = (char *)malloc(sizeof(char) * 3 + 1);
		index++;
	}
	return (numbers);
}

void	ft_fill_zero(char **numbers, int one_digit, int *row, int *col)
{
	int	zero_count;

	zero_count = 0;
	if (*col != 0)
		return ;
	while (one_digit + zero_count < 3 && one_digit != 0)
	{
		*(numbers[*col] + *row) = '0';
		*row += 1;
		zero_count++;
	}
}

void	ft_str_fill(char **numbers, char *str, int one_digit)
{
	int	index;
	int	col_index;
	int	row_index;

	index = 0;
	col_index = 0;
	row_index = 0;
	while (*(str + index))
	{
		ft_fill_zero(numbers, one_digit, &row_index, &col_index);
		*(numbers[col_index] + row_index) = *(str + index);
		if (index == one_digit - 1)
		{
			col_index++;
			row_index = -1;
		}
		else if ((index - one_digit + 1) % 3 == 0)
		{
			col_index++;
			row_index = -1;
		}
		row_index++;
		index++;
	}
	*(numbers + col_index) = 0;
}

char	**ft_str_cut(char *str)
{
	int		length;
	int		digit;
	int		one_digit;
	char	**numbers;

	digit = 0;
	one_digit = 0;
	length = ft_strlen(str);
	numbers = ft_str_memory(length, &digit, &one_digit);
	ft_str_fill(numbers, str, one_digit);
	return (numbers);
}
