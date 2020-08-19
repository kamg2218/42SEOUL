/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:20:15 by hyoon             #+#    #+#             */
/*   Updated: 2020/08/16 22:20:17 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		UTILS_H
# define	UTILS_H

# include <string.h>

int		ft_isalnum(int c);
int		ft_strlen(char *string);
int		num_in_line(char *line);
int		char_to_num(char *line, int *num);
int		ft_endwidth(char *str1, char *str2);
int		*ft_memset(int *ptr, int value, size_t num);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
