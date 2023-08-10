NAME		= account
COMP		= c++
FLAGS		= -Wall -Wextra -Werror -std=c++11
RM			= rm -f
INC			= Account.hpp
OBJ			= $(SRC:.cpp=.o)
SRC			= tests.cpp \
				Account.cpp

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(COMP) -I $(INC) $(OBJ) -o $(NAME)

%.o: %.c
	$(COMP) $(FLAGS) $(SRC) -c -o $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
