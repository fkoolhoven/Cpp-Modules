NAME		= BSP
COMP		= c++
FLAGS		= -Wall -Wextra -Werror -std=c++11
RM			= rm -f
INC_DIR		= inc
INCLUDES	= inc/Point.hpp
SRC_DIR		= src
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SRC			= main.cpp \
				Fixed.cpp \
				Point.cpp

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(COMP) -I $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	$(RM)r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
