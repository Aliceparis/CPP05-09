NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -g3

SRC = PmergeMe.cpp\
	main.cpp
	
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(DEP)
fclean: clean
	rm -rf $(NAME)
re: fclean all 
.PHONY: all clean fclean re 