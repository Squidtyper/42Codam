# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/15 14:36:39 by lizhang       #+#    #+#                  #
#    Updated: 2023/05/05 18:26:59 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= animal
CC			= g++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
INCLUDE		= -IAnimal.hpp -ICat.hpp -IDog.hpp -IWrongAnimal.hpp -IBrain.hpp
SRC			= Animal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp
RM			= rm -f
OBJ			= $(SRC:.cpp=.o)

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re