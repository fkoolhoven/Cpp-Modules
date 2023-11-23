NAME	= sed
COMP	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++14
RM		= rm -f
OBJ		= $(SRC:.cpp=.o)
SRC		= main.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
