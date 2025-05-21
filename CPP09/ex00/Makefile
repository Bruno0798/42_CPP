NAME = btc

# Source and header files
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Default target
all: $(NAME)

# Link the executable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: re
	clear; ./$(NAME) input.txt

# Leaks/Valgrind test target
leaks: $(NAME)
ifeq ($(shell uname), Darwin)
	leaks -atExit -- ./$(NAME) input.txt
else
	valgrind --leak-check=full --track-origins=yes ./$(NAME) input.txt
endif

.PHONY: all clean fclean re run leaks
