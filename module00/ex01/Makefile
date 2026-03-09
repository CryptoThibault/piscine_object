NAME = ex01
SRCS = main.cpp Vector2.cpp Graph.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re