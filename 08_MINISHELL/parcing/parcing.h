/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:45:11 by jikwon            #+#    #+#             */
/*   Updated: 2021/01/30 20:24:03 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include "../util/libft.h"

# define PIPE 1
# define GREAT 2
# define LESS 3
# define GREATGREAT 4
# define SEMI 5
# define DOLLAR 1000
# define BACKSL 92

typedef struct	s_var
{
	char			*key;
	char			*value;
	struct s_var	*next;
}				t_var;

typedef struct	s_cmd
{
	char			*str;
	int				type;
	char			del;
	struct s_cmd	*bef;
	struct s_cmd	*next;
}				t_cmd;

typedef struct	s_mini
{
	int		tmpin;
	int		tmpout;
	int		fdin;
	int		fdout;
	int		file;
	int		exit;
	int		parent;
	t_cmd	*start;
	int		pipe;
	int		signal;
	int		sigint;
	t_var	*env;
	t_cmd	*cmd;
	char	**envp;
}				t_mini;

typedef struct	s_operator
{
	int	*type;
	int	*index;
	int	cnt;
}				t_operator;

typedef struct	s_quote
{
	int		i;
	int		quote;
	int		index;
	int		res;
	int		exp;
	char	*str;
}				t_quote;

t_mini			g_mini;

/*
** parcing.c
*/

t_cmd			*split_op(char *str, t_operator op_info);
void			handle_quote_env(t_cmd **start);
char			*handle_quotes(char *str, t_quote *q_val);
t_cmd			*tokenize(char *user_input);
int				only_env(char *str);

/*
**lst_utils.c
*/

void			ft_lstmerge(t_cmd *bef, t_cmd *aft);
t_cmd			*ft_lst_start(char *str, int type);
void			ft_lstadd(t_cmd *start, char *str, int type);
void			free_cmd(t_cmd *start);

/*
**utils.c
*/

char			*ft_strldup(char *str, int start, int end);
int				ft_strcmp(char *s1, char *s2);
void			*malloc_error(void);
int				syntax_error(char *cmd);
int				quote_error(char *input);

/*
**backslash.h
*/

char			*process_bs(char *str, int option, int len);
void			check_bs(char **str, int option);
void			convert_bs(t_cmd *pos);

/*
**env.c
*/

void			charadd(char **str, char c);
char			*search_env(char *key, t_var *env);
char			*find_val(char *str, int *i, t_var *env);
char			*convert_env(char *str, t_var *env);
char			*pos_env(char *str);

/*
**quote_env.c
*/

void			treat_string(t_quote *q_val, char **result);
void			treat_single(t_quote *q_val, char **reuslt);
void			treat_double(t_quote *q_val, char **result);
void			check_dollar(char *str);
void			for_env_dist(char **result);

/*
**quote_utils1.c
*/

int				is_quotes(char c, char bef, int quotes);
int				wh_quotetype(char bef, char c);
int				set_i(int i, char cur, int quote);
int				no_quote(t_quote q_val);

/*
**quote_utlis2.c
*/

int				wh_quotedstr(t_quote q_val);
char			*init_handle_quotes(t_quote *q_val, char *str);
char			*trim_quote(char *str);
int				next_step(t_quote *q_val);

/*
**parce_op.c
*/

int				cnt_operator(char *str);
int				dist_operator(char *str, int i);
int				dist_optype(t_operator op_info, int i);
char			*convert_op(t_operator op_info, int i);
void			find_operator(char *str, t_operator *op_info);

/*
**utils_op.c
*/

void			malloc_info(t_operator *op_info);
char			*ldup_trim(char *str, int start, int end);
void			initzero(int *i, int *j, int *quote);
int				is_opcha(char cur);
void			free_struct(t_operator tar);

/*
**parce_sp.c
*/

int				cnt_space(char *str);
void			set_idx(char *str, int **idx, int cnt);
void			new_cmd(t_cmd **res, char *temp);
t_cmd			*process_split(t_cmd *tar, int cnt);
t_cmd			*split_space(t_cmd *start);

/*
**rearrange.c
*/

void			move_forward(t_cmd **start, t_cmd *red, t_cmd *pos);
void			re_arrange(t_cmd **start);
#endif
