NAME = log

SRC =	Account.cpp \
		tests.cpp
OBJ = $(SRC:.cpp=.o)

CFLAGS = -std=c++98 #-Wall -Werror -Wextra

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
