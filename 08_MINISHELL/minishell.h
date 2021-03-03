/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:25:24 by hyoon             #+#    #+#             */
/*   Updated: 2021/01/31 16:02:05 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include "util/get_next_line.h"
# include "util/libft.h"
# include "parcing/parcing.h"

# define APPEND	0
# define TRUNC	1
# define INPUT	2
# define STDIN	0
# define STDOUT	1

typedef struct		s_node
{
	char			*key;
	char			*value;
	int				print;
	struct s_node	*prev;
	struct s_node	*left_next;
	struct s_node	*right_next;
}					t_node;

typedef struct		s_pipe
{
	int				count;
	int				len;
	t_cmd			*start;
	int				**fdpipe;
}					t_pipe;

/*
**	draw.c
*/

void				drawing_side(void);
void				drawing_start(void);

/*
**	util.c
*/

int					first_command(void);
int					command_length(void);
int					last_command(void);
void				arrange_command(t_cmd *cmd);
t_cmd				*clear_cmd(t_cmd *head, t_cmd *tmp);

/*
**	mini_util.c
*/

void				ft_close(void);
void				mini_init(void);
int					is_last_cmd(t_cmd *cmd);

/*
** status.c
*/

void				check_last(t_cmd *cmd);
void				set_status(int status);

/*
**	signal.c
*/

void				handle_sigint(int sig);
void				handle_sigquit(int sig);

/*
**	error.c
*/

void				*no_such_file(char *cmd);
void				bad_assignment(char *cmd);
int					not_enough(char *cmd);
int					is_not_command(char *cmd);
int					no_valid_identifier(char *cmd);

/*
**	redirection.c
*/

int					redirection_input(t_cmd *tmp);
int					redirection(int type, t_cmd *tmp);

/*
**	pipe.c
*/

void				piping(int len);
void				pipe_process(int i, t_pipe *pipe);
void				arrange_inout(int i, t_pipe *pipe);
void				close_pipe(int **fdpipe, int count);
int					**get_fdpipe(t_pipe *pipe);

/*
**	path.c
*/

int					absolute_path(char *cmd, char *str);
int					relative_path(char *cmd, char *str);
int					check_directory(char *path, char *cmd);
int					change_cmd(char *cmd, char *str, int len);
int					environment_path(t_var *lst, char *cmd, char *str);

/*
**	builtin.c
*/

int					is_builtin(char *str);

/*
**	minishell.c
*/

void				command_line(t_cmd *cmd);
int					change_inout(t_cmd *tmp);

/*
**	cmd.c
*/

int					is_command(t_cmd *cmd);
int					preprocess_command(t_cmd *cmd);
int					check_strncmp(char *cmd, char *str);
void				get_command(void);
char				*get_path(t_var *lst, int start, int len);

/*
**	cd.c
*/

char				*cd_wave(t_var *env);
int					is_pipe_in_cmd(void);
int					ft_cd(t_cmd *cmd, t_var *env);
void				variable_strjoin(char *value, t_var *tmp);

/*
**	pwd.c
*/

int					ft_pwd(t_var *env);
int					count_slash(char *value);
void				get_rid_of_dots(char *value, t_var *tmp, int len);
void				change_pwd(char *value, t_var *tmp);
void				change_oldpwd(t_var *tmp);

/*
**	echo.c
*/

int					ft_echo(t_cmd *cmd);
t_cmd				*put_string(t_cmd *cmd);
t_cmd				*find_position(t_cmd *cmd, int *opt);

/*
**	export.c
*/

int					export_single(t_var *env);
int					ft_export(t_cmd *cmd, t_var *env);
void				export_long(t_cmd *cmd, t_var *env);

/*
**	export_util.c
*/

void				print_export(t_node *tmp);
void				export_env(t_var *env, t_var *new, int k_len);
int					get_export_len(int *len, t_cmd *tmp);

/*
**	node.c
*/

void				destroy(t_node **head);
void				traverse(t_node *head);
void				insert(t_node **head, t_node *new);
t_node				*create(char *key, char *value);
t_node				*move_tmp(t_node *tmp, t_node *new);

/*
**	env.c
*/

int					ft_env(t_cmd *cmd, t_var *t_env);
t_var				*make_env(char **envp);

/*
**	env_util.c
*/

void				ft_varclear(t_var **var);
void				check_environ(t_cmd *tmp);
void				ft_varadd_back(t_var **var, t_var *new);
t_var				*ft_varnew(int key, int value);
t_cmd				*check_del(t_cmd *pre, t_cmd *tmp);

/*
**	unset.c
*/

int					ft_unset(t_cmd *cmd, t_var *env);
void				connect_var(t_var *pre, t_var *tmp);
void				unset_var(t_cmd *cmd, t_var *env, int len);

/*
**	else.c
*/

int					ft_else(t_cmd *cmd);
char				**make_string(t_cmd *cmd);
char				*check_command(t_cmd *cmd);

#endif
