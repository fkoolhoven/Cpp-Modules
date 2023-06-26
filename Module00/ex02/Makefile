NAME		= account
COMP		= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f
INCLUDES	= Account.hpp
OBJ			= $(SRC:.cpp=.o)
SRC			= tests.cpp \
				Account.cpp

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(COMP) -I $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c
	$(COMP) $(FLAGS) $(SRC) -c -o $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all