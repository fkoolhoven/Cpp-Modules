NAME	= claptrap
COMP	= c++
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f
INC		= inc/ScavTrap.hpp
SRC_DIR	= src
OBJ_DIR	= obj
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SRC		= main.cpp ClapTrap.cpp ScavTrap.cpp

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(COMP) -I $(INC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	$(RM)r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
