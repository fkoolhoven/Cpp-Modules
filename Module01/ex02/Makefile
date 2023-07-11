NAME	= brain	
SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)
COMP	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(COMP) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all