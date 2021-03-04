NAME = philo_one

CFLAGS = -Werror -Wextra -Wall

SRC = philo_one.c\
	  util.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
