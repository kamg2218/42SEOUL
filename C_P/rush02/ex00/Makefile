NAME = rush-02

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c ft_data_parsing.c ft_data_parsing2.c ft_str_cut.c ft_util.c \
	   ft_validate_dict.c ft_validate_value.c 

RM = rm -f

${NAME}:
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

all :	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
