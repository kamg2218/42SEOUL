NAME = libstack.a

SRC = size.c\
	  empty.c\
	  pop.c\
	  top.c\
	  clear.c\
	  push.c\
	  new.c

OBJECTS = *.o
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
