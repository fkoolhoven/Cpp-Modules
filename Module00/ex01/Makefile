NAME		= phonebook
COMP		= c++
FLAGS		= -Wall -Wextra -Werror -std=c++14
RM			= rm -f
INC			= -Iinc
SRC_DIR		= src
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SRC			= main.cpp \
				PhoneBook.cpp \
				Contact.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(COMP) $(FLAGS) $(INC) -c $< -o $@

clean:
	$(RM)r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
