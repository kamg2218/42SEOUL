NAME = libft.a

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	ft_isprint.c ft_memset.c ft_tolower.c ft_toupper.c ft_atoi.c\
	ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
	ft_strchr.c ft_strlen.c ft_strrchr.c ft_calloc.c ft_strdup.c\
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c\
	ft_strtrim.c ft_substr.c ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strmapi.c

SR = *.c
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

bonus : fclean
	gcc $(CFLAGS) -c $(SR)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

re : fclean all