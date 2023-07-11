NAME	= zombie	
SRC		= main.cpp \
			newZombie.cpp \
			Zombie.cpp \
			randomChump.cpp
OBJ		= $(SRC:.cpp=.o)
INC		= Zombie.hpp
COMP	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(COMP) -I $(INC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all