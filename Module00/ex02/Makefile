NAME		= account
COMP		= c++
FLAGS		= -Wall -Wextra -Werror -std=c++14
RM			= rm -f
OBJ			= $(SRC:.cpp=.o)
SRC			= tests.cpp Account.cpp

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(COMP) $(OBJ) -o $(NAME)

%.o: %.c
	$(COMP) $(FLAGS) $(SRC) -c -o $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all