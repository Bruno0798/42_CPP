NAME = RPN

SRC = main.cpp RPN.cpp
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

# Leaks/Valgrind test target
leaks: $(NAME)
ifeq ($(OS), Darwin)
	leaks -atExit -- ./$(NAME)
else
	valgrind --leak-check=full --track-origins=yes ./$(NAME) input.txt
endif

test: $(NAME)
	@echo "\033[1;34m=================== Running RPN Tests ===================\033[0m"
	@i=1; \
	while IFS='|' read -r input expected || [ -n "$$input" ]; do \
		input=$$(echo "$$input" | sed 's/^[ \t]*//;s/[ \t]*$$//'); \
		expected=$$(echo "$$expected" | sed 's/^[ \t]*//;s/[ \t]*$$//'); \
		if [ -z "$$input" ] || echo "$$input" | grep -q '^#'; then continue; fi; \
		if [ "$$input" = "(empty)" ]; then input=""; fi; \
		echo "\033[1;33m[$$i] Input: '$$input'\033[0m"; \
		output=$$(./$(NAME) "$$input" 2>&1); \
		if [ "$$output" = "$$expected" ]; then \
			echo "\033[1;32m✓ Output: '$$output' (PASS)\033[0m"; \
		else \
			echo "\033[1;31m𐄂 Output: '$$output' (FAIL)\033[0m"; \
			echo "   Expected: '$$expected'"; \
		fi; \
		echo ""; \
		i=$$(($$i + 1)); \
	done < tests.txt; \
	true
	@echo "\033[1;34m================== Test Run Complete ===================\033[0m"
