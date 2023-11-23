NAME	= harlFilter
COMP	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++14
RM		= rm -f
INC		= Harl.hpp
OBJ		= $(SRC:.cpp=.o)
SRC		= main.cpp Harl.cpp

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
