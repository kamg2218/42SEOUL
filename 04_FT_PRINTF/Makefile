NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = printf.c printf_parcing.c printf_utils.c printf_diu.c\
		 printf_utils_second.c printf_csp.c
OBJS = printf.o printf_parcing.o printf_utils.o printf_diu.o\
	   printf_utils_second.o printf_csp.o

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(TARGET)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
