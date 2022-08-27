NAME = bureaucrat

srcs = $(wildcard ./*.cpp) \
		$(wildcard ./ex02/ex01/ex00/*.cpp) \
		$(wildcard ./ex02/ex01/*.cpp) \
		$(wildcard ./ex02/*.cpp)

objs = $(srcs:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address -pedantic
CXX = c++

all: $(NAME)

$(NAME): $(objs)
	$(CXX) $(CXXFLAGS) $(objs) -o $(NAME)

clean:
	$(RM) ./$(objs)

fclean: clean
	$(RM) $(NAME)
	$(RM)  *_shrubbery
re: fclean all

run: all
	./$(NAME)

out: all
	./$(NAME) 2>/dev/null

err: all
	./$(NAME) 1>/dev/null

.PHONY: all clean fclean re
