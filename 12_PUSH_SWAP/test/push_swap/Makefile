NAME = push_swap

SRC = main.c\
	  command.c\
	  sort_else.c\
	  sort_three.c\
	  utils.c\
	  pre_processing.c

OBJECTS = *.o
CFLAGS = -L../utils -lft -L../utils/libstack -lstack
DFLAGS = -Wall -Wextra -Werror -fsanitize=address

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) $(DFLAGS) -o $(NAME) $(SRC)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
