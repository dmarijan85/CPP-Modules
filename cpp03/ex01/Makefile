NAME = ScavTrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

HEADERS = ClapTrap.hpp ScavTrap.hpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Werror -Wextra -std=c++98 #-g -fsanitize=address

REMOVE = rm -f

all: $(NAME)

$(NAME): Makefile $(OBJ) $(HEADERS)
	@$(COMPILE) $(SRC) -o $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY = all clean fclean re
