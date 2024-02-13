NAME		= bureaucrat
COMP		= c++
FLAGS		= -Wall -Wextra -Werror -std=c++14
LEAK_CHECK	= -fsanitize=address -g -fsanitize=leak
RM			= rm -f
INC			= inc
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SRC_DIR		= src
SRC			= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(LEAK_CHECK) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(COMP) $(LEAK_CHECK) -I $(INC) $(FLAGS) -c $< -o $@

clean:
	$(RM)r $(OBJ_DIR)
	$(RM) Tree_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all