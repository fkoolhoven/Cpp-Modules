NAME		= phonebook
COMP		= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f
INC_DIR		= inc
INCLUDES	= inc/Phonebook.hpp
SRC_DIR		= src
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SRC			= main.cpp \
				PhoneBook.cpp \
				Contact.cpp

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
