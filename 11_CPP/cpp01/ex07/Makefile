NAME = replacement

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -std=c++98

SRC = main.cpp\
	  stream.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o: %.cpp
	clang++ $(CFLAGS) $(DFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	clang++ $(CFLAGS) $(DFLAGS) -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all	
