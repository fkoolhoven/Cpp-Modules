NAME	= zombie	
OBJ		= $(SRC:.cpp=.o)
INC		= Zombie.hpp
COMP	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++14
RM		= rm -f
SRC		= main.cpp \
			newZombie.cpp \
			Zombie.cpp \
			randomChump.cpp

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