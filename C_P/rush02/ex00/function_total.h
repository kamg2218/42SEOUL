/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_total.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:20:08 by dokang            #+#    #+#             */
/*   Updated: 2020/02/09 23:34:56 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_TOTAL_H
# define FUNCTION_TOTAL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_data
{
	char key[10000];
	char value[10000];
}				t_data;
/*
** util_functions. ft_sam is used to cut string for every three digits.
*/
void			ft_print(char *str, int check);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
void			ft_sam(t_data *data, char *str, int n);
/*
** parse data to make a dictionary format.
*/
void			ft_strcpy(char *dest, char *from, char *to);
void			ft_split(char *str, t_data *data);
int				ft_in_data(t_data *data, char *str, int count);
int				mal_len(void);
int				ft_fill_data(char *buf, t_data *data);
t_data			*ft_initialize(void);
void			ft_cut(t_data *data, char *str);
int				ft_numeric_check(char *argv);
/*
** cut input string to read a number.
*/
char			**ft_str_memory(int length, int *digit, int *one_digit);
void			ft_fill_zero(char **numbers, int one_digit, int *row, int *col);
void			ft_str_fill(char **numbers, char *str, int one_digit);
char			**ft_str_cut(char *str);
void			ft_sam_check(t_data *data, int n);
/*
** validate if the input has the right value.
*/
int				ft_is_space(char *str);
int				ft_is_non_printable(char *str);
int				ft_is_numeric(char c);
int				ft_validate_key(char *str);
int				ft_validate_value(char *str);
int				ft_validate_dict(char *str);
int				ft_full_check(t_data *data, char *argv);

#endif
