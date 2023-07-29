NAME	= fixed
COMP	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f
INC		= Fixed.hpp
OBJ		= $(SRC:.cpp=.o)
SRC		= main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) -I $(INC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
