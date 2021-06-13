NAME = checker

SRC = main.c\
	  ../utils/get_next_line_bonus.c\
	  ../utils/get_next_line_utils_bonus.c

OBJECTS = *.o
CFLAGS = -L../utils -lft -L../utils/libstack -lstack
DFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) $(DFLAGS) -o $(NAME) $(SRC)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
