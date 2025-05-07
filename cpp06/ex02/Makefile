NAME = Base

SRC = Base.cpp main.cpp A.cpp B.cpp C.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Werror -Wextra -std=c++98 #-g -fsanitize=address

REMOVE = rm -f

HEADERS = Base.hpp A.hpp B.hpp C.hpp

all: $(NAME) $(BONUS)

$(NAME): Makefile $(OBJ) $(HEADERS)
	@$(COMPILE) $(OBJ) -o $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY = all clean fclean re
