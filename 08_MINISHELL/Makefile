NAME = minishell

CFLAGS = -Lutil -lft

DFLAGS = -D BUFFER_SIZE=1

EFLAGS = -Wall -Wextra -Werror

SRC = minishell.c\
	  builtin/draw.c\
	  builtin/cmd.c\
	  builtin/cd.c\
	  builtin/util.c\
	  builtin/pwd.c\
	  builtin/echo.c\
	  builtin/signal.c\
	  builtin/env.c\
	  builtin/env_util.c\
	  builtin/export.c\
	  builtin/export_util.c\
	  builtin/unset.c\
	  builtin/redirection.c\
	  builtin/error.c\
	  builtin/else.c\
	  builtin/path.c\
	  builtin/mini_util.c\
	  builtin/status.c\
	  builtin/pipe.c\
	  builtin/node.c\
	  builtin/builtin.c\
	  parcing/parcing.c\
	  parcing/rearrange.c\
	  parcing/backslash.c\
	  parcing/quote_env.c\
	  parcing/quote_utils1.c\
	  parcing/quote_utils2.c\
	  parcing/utils.c\
	  parcing/env.c\
	  parcing/op.c\
	  parcing/op_utils.c\
	  parcing/lst_utils.c\
	  parcing/sp.c\
	  util/get_next_line.c\
	  util/get_next_line_utils.c\
	  util/get_next_line_lst.c

OBJECTS = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	gcc $(CLFAGS) $(DFLAGS) $(EFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	gcc $(CFLAGS) $(DFLAGS) $(EFLAGS) -o $(NAME) $(OBJECTS)

clean :
	/bin/rm -f $(OBJECTS)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
