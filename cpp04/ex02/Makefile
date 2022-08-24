NAME = animal
srcs = $(wildcard ./*.cpp) \
		$(wildcard ./ex00/*.cpp)
objs = $(srcs:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -pedantic
CXX = c++

all: $(NAME)

$(NAME): $(objs)
	$(CXX) $(CXXFLAGS) $(objs) -o $(NAME)

clean:
	$(RM) ./$(objs)
	$(RM) ./ex00/$(objs)

fclean: clean
	$(RM) $(NAME)
re: fclean all

run: all
	./$(NAME)

out: all
	./$(NAME) 2>/dev/null

err: all
	./$(NAME) 1>/dev/null

.PHONY: all clean fclean re
