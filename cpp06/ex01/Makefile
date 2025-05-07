NAME = serialize

SRC = Serializer.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Werror -Wextra -std=c++98 #-g -fsanitize=address

REMOVE = rm -f

HEADERS = Serializer.hpp Data.hpp

all: $(NAME) $(BONUS)

$(NAME): Makefile $(OBJ) $(HEADERS)
	@$(COMPILE) $(OBJ) -o $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY = all clean fclean re
