NAME		= whatever
COMP		= c++
FLAGS		= -Wall -Wextra -Werror -std=c++14
RM			= rm -f
INC			= inc
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SRC_DIR		= src
SRC			= main.cpp whatever.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(COMP) -I $(INC) $(FLAGS) -c $< -o $@

clean:
	$(RM)r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all