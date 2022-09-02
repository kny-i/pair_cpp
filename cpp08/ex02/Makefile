NAME = mutantstack
srcs = $(wildcard ./*.cpp)
objs = $(srcs:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic #-fsanitize=address
CXX = c++

all: $(NAME)

$(NAME): $(objs)
	$(CXX) $(CXXFLAGS) $(objs) -o $(NAME)

clean:
	$(RM) ./$(objs)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME)

out: all
	./$(NAME) 2>/dev/null

err: all
	./$(NAME) 1>/dev/null

leaks: all
	leaks -q --atExit -- ./$(NAME)

.PHONY: all clean fclean re out err run

