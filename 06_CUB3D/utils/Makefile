NAME = libutils.a

SRC = ft_endwidth.c\
	  ft_memcmp.c\
	  ft_isalnum.c\
	  ft_strlen.c\
	  ft_memset.c\
	  char_to_num.c\
	  num_in_line.c

OBJECTS = ft_endwidth.o\
		  ft_memcmp.o\
		  ft_isalnum.o\
		  ft_strlen.o\
		  ft_memset.o\
		  char_to_num.o\
		  num_in_line.o

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcv $@ $(OBJECTS)
	ranlib $@

clean :
	/bin/rm -f $(OBJECTS)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
