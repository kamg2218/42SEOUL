NAME = ScalarConversion

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -std=c++98

SRC = main.cpp\
	  srcs/ConvertToChar.cpp\
	  srcs/ConvertToInt.cpp\
	  srcs/ConvertToFloat.cpp\
	  srcs/ConvertToDouble.cpp

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
