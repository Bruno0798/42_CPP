NAME = zombie

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
		c++ -o $(NAME) $(OBJ)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

# Leaks test target
leaks: $(NAME)
	leaks -atExit -- ./$(NAME)
