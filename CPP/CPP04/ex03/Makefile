# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/15 14:36:39 by lizhang       #+#    #+#                  #
#    Updated: 2023/05/07 13:26:24 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= materia
CC			= g++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
INCLUDE		= -IICharacter.hpp -IAMateria.hpp -IMateriaSource.hpp \
			-ICharacter.hpp -IIce.hpp -ICure.hpp
SRC			= Character.cpp AMateria.cpp MateriaSource.cpp Ice.cpp Cure.cpp main.cpp 
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