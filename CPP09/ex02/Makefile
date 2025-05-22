NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

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

run: re
	clear
	./$(NAME) 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

# Leaks/Valgrind test target
leaks: $(NAME)
ifeq ($(OS), Darwin)
	leaks -atExit -- ./$(NAME) 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
else
	valgrind --leak-check=full --track-origins=yes ./$(NAME) `shuf -i 1-100000 -n 99 | tr "\n" " "`
endif
