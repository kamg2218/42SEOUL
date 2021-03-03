/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:26:29 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/24 02:32:42 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t			ft_strlcpy(char *dst, const char *src, size_t n);
size_t			ft_strlen(const char *string);
int				ft_isalnum(int c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
void			*ft_memcpy(void *dst, const void *source, size_t num);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(char const *s);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);

#endif
