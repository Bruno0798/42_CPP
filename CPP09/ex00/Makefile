NAME = btc

# Source and header files
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -O2 -pedantic
DEPFLAGS = -MMD -MP

# Include dependency files
-include $(DEPS)

# Default target
all: $(NAME)

# Link the executable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

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
# Test target that runs basic validation tests
TEST_DIR = tests
test: $(NAME)
	@echo "Running tests..."
	@mkdir -p $(TEST_DIR)
	
	@echo "\n--- Testing valid input ---"
	@echo "date | value" > $(TEST_DIR)/basic_test.txt
	@echo "2019-01-01 | 1" >> $(TEST_DIR)/basic_test.txt
	@echo "2020-05-15 | 42" >> $(TEST_DIR)/basic_test.txt
	@echo "2022-12-31 | 100" >> $(TEST_DIR)/basic_test.txt
	@./$(NAME) $(TEST_DIR)/basic_test.txt || echo "❌ Basic test failed!"
	
	@echo "\n--- Testing invalid dates ---"
	@echo "date | value" > $(TEST_DIR)/invalid_dates.txt
	@echo "2009-13-01 | 1" >> $(TEST_DIR)/invalid_dates.txt  # Invalid month
	@./$(NAME) $(TEST_DIR)/invalid_dates.txt 2>&1 | grep -q "Month cant be bigger than 12" && echo "✅ Invalid month test passed!" || echo "❌ Invalid month test failed!"
	
	@echo "date | value" > $(TEST_DIR)/invalid_dates.txt
	@echo "2009-00-01 | 1" >> $(TEST_DIR)/invalid_dates.txt  # Month too low
	@./$(NAME) $(TEST_DIR)/invalid_dates.txt 2>&1 | grep -q "Month cant be lower than 1" && echo "✅ Month too low test passed!" || echo "❌ Month too low test failed!"
	
	@echo "date | value" > $(TEST_DIR)/invalid_dates.txt
	@echo "2008-01-01 | 1" >> $(TEST_DIR)/invalid_dates.txt  # Year too early
	@./$(NAME) $(TEST_DIR)/invalid_dates.txt 2>&1 | grep -q "Year cant be lower than 2009" && echo "✅ Year too early test passed!" || echo "❌ Year too early test failed!"
	
	@echo "date | value" > $(TEST_DIR)/invalid_dates.txt
	@echo "2030-01-01 | 1" >> $(TEST_DIR)/invalid_dates.txt  # Year too late
	@./$(NAME) $(TEST_DIR)/invalid_dates.txt 2>&1 | grep -q "Year cant be bigger than 2025" && echo "✅ Year too late test passed!" || echo "❌ Year too late test failed!"
	
	@echo "date | value" > $(TEST_DIR)/invalid_dates.txt
	@echo "2020-04-31 | 1" >> $(TEST_DIR)/invalid_dates.txt  # Invalid day for month
	@./$(NAME) $(TEST_DIR)/invalid_dates.txt 2>&1 | grep -q "Invalid day for this month" && echo "✅ Invalid day for month test passed!" || echo "❌ Invalid day for month test failed!"
	
	@echo "\n--- Testing invalid values ---"
	@echo "date | value" > $(TEST_DIR)/invalid_values.txt
	@echo "2020-01-01 | -5" >> $(TEST_DIR)/invalid_values.txt  # Negative value
	@./$(NAME) $(TEST_DIR)/invalid_values.txt 2>&1 | grep -q "Value cant be lower than 0" && echo "✅ Negative value test passed!" || echo "❌ Negative value test failed!"
	
	@echo "date | value" > $(TEST_DIR)/invalid_values.txt
	@echo "2020-01-01 | 2000" >> $(TEST_DIR)/invalid_values.txt  # Value too large
	@./$(NAME) $(TEST_DIR)/invalid_values.txt 2>&1 | grep -q "Value cant be bigger than 1000" && echo "✅ Value too large test passed!" || echo "❌ Value too large test failed!"
	
	@echo "\n--- Testing malformed input ---"
	@echo "date | value" > $(TEST_DIR)/malformed.txt
	@echo "2020-01-01 1" >> $(TEST_DIR)/malformed.txt  # Missing pipe
	@./$(NAME) $(TEST_DIR)/malformed.txt 2>&1 | grep -q "Error: bad input" && echo "✅ Missing pipe test passed!" || echo "❌ Missing pipe test failed!"
	
	@echo "date | value" > $(TEST_DIR)/malformed.txt
	@echo "2020-01-01 | abc" >> $(TEST_DIR)/malformed.txt  # Non-numeric value
	@./$(NAME) $(TEST_DIR)/malformed.txt 2>&1 | grep -q "invalid value" && echo "✅ Non-numeric value test passed!" || echo "❌ Non-numeric value test failed!"
	
	@echo "date | value" > $(TEST_DIR)/malformed.txt
	@echo "01/01/2020 | 10" >> $(TEST_DIR)/malformed.txt  # Wrong date format
	@./$(NAME) $(TEST_DIR)/malformed.txt 2>&1 | grep -q "Missing fields from date\|Error:" && echo "✅ Wrong date format test passed!" || echo "❌ Wrong date format test failed!"
	
	@echo "\n--- Testing empty file ---"
	@echo "" > $(TEST_DIR)/empty.txt
	@./$(NAME) $(TEST_DIR)/empty.txt 2>&1 | grep -q "Warning: Input file is empty" && echo "✅ Empty file test passed!" || echo "❌ Empty file test failed!"

# Check for header guards in all header files
check-guards:
	@for file in $(wildcard *.hpp); do \
		guard=`echo $$file | tr '[:lower:].' '[:upper:]_'`; \
		if ! grep -q "\#ifndef $$guard" $$file || ! grep -q "\#define $$guard" $$file; then \
			echo "❌ Header guard missing or incorrect in $$file"; \
		else \
			echo "✅ Header guard OK in $$file"; \
		fi; \
	done

# Code analysis target
analyze:
	@echo "Running code analysis..."
	@which cppcheck > /dev/null && cppcheck --enable=all --std=c++98 --suppress=missingIncludeSystem $(SRC) || echo "cppcheck not installed"

# Full test suite
check: $(NAME) test check-guards analyze

.PHONY: all clean fclean re run leaks test check-guards analyze check
