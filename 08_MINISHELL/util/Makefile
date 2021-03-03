NAME = libft.a

SRC = ft_strlen.c\
	ft_strlcpy.c\
	ft_strncmp.c\
	ft_split.c\
	ft_memcpy.c\
	ft_strjoin.c\
	ft_strdup.c\
	ft_putstr_fd.c\
	ft_strtrim.c\
	ft_isalnum.c\
	ft_itoa.c\

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
