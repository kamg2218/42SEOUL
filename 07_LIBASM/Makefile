NAME = libasm.a

SRC = 		ft_strlen.s\
	  		ft_strcpy.s\
	  		ft_strcmp.s\
	  		ft_write.s\
	  		ft_read.s\
	  		ft_strdup.s

SRC_BONUS = ft_atoi_base_bonus.s\
	 	 	ft_list_push_front_bonus.s\
	 		ft_list_size_bonus.s\
	  		ft_list_sort_bonus.s\
	  		ft_list_remove_if_bonus.s

OBJS =		ft_strlen.o\
	  		ft_strcpy.o\
	  		ft_strcmp.o\
	  		ft_write.o\
	  		ft_read.o\
	  		ft_strdup.o

OBJS_BONUS = ft_atoi_base_bonus.o\
			 ft_list_push_front_bonus.o\
			 ft_list_size_bonus.o\
			 ft_list_sort_bonus.o\
			 ft_list_remove_if_bonus.o

BONUS = libasm_bonus.a

%.o :			%.s
				nasm -f macho64 $<

all : $(NAME)

$(NAME) :		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus :	$(BONUS)

$(BONUS) :		$(OBJS) $(OBJS_BONUS)
				ar rcs $(BONUS) $(OBJS) $(OBJS_BONUS)

clean :
				rm -rf $(OBJS) $(OBJS_BONUS)

fclean :		clean
				rm -rf $(NAME) $(BONUS) test test_bonus

re :	 		fclean all

test : 			$(NAME)
				gcc -L. -lasm -o test main.c
				./test

test_bonus :	$(BONUS)
				gcc -L. -lasm_bonus -o test_bonus main_bonus.c
				./test_bonus
