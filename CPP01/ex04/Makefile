# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 11:33:35 by dmarijan          #+#    #+#              #
#    Updated: 2025/01/10 17:23:04 by dmarijan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = loser

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Werror -Wextra -std=c++98 #-g -fsanitize=address

REMOVE = rm -f

all: $(NAME) $(BONUS)

$(NAME): Makefile $(OBJ)
	@$(COMPILE) $(SRC) -o $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY = all clean fclean re
