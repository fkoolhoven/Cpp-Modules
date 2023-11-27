NAME	= megaphone
COMP	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++14
OBJ		= $(SRC:.cpp=.o)
SRC		= megaphone.cpp
RM		= rm

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(COMP) $(FLAGS) $(SRC) -c -o $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all