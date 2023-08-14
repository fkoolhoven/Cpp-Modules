NAME	= claptrap
COMP	= c++
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f
INC		= ClapTrap.hpp
OBJ		= $(SRC:.cpp=.o)
SRC		= main.cpp ClapTrap.cpp

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
