NAME = cub3D

SRC = raycast.c\
	  cub3d.c\
	  key.c\
	  bmp.c\
	  color.c\
	  sprite.c\
	  color_sprite.c\
	  calculate_sprite.c\
	  ./parsing/map.c\
	  ./parsing/xpm.c\
	  ./parsing/parsing_map.c\
	  ./parsing/parsing_sprite.c\
	  ./parsing/parsing_cub.c\
	  ./parsing/dfs.c\
	  ./parsing/checking_map.c\
	  ./parsing/get_next_line.c\
	  ./parsing/get_next_line_utils.c\

OBJECTS = raycast.o\
		  cub3d.o\
		  key.o\
		  bmp.o\
		  color.o\
		  sprite.o\
		  color_sprite.o\
		  calculate_sprite.o\
		  map.o\
		  xpm.o\
		  parsing_map.o\
		  parsing_sprite.o\
		  parsing_cub.o\
		  dfs.o\
		  get_next_line.o\
		  get_next_line_utils.o\
		  checking_map.o\

CFLAGS = -L./mlx_opengl -lmlx -framework OpenGL -framework AppKit

DFLAGS = -D BUFFER_SIZE=1024

EFLAGS = -L./utils -lutils

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) $(DFLAGS) $(EFLAGS) -o $(NAME) $(SRC)

clean :
	/bin/rm -f $(OBJECTS)

fclean :
	/bin/rm -f $(NAME)

re : fclean all
