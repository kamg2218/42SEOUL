NAME = push_swap

SRC = main.c

OBJECTS = *.o
CFLAGS = -L. -lft -L./libstack -lstack
DFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) $(DFLAGS) -o $(NAME) $(SRC)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
