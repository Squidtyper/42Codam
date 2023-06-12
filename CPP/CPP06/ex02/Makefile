# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/21 12:59:42 by lizhang       #+#    #+#                  #
#    Updated: 2023/06/11 12:28:39 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= identity
CC			= g++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
INCLUDE		= -IBase.hpp -IA.hpp -IB.hpp -IC.hpp
SRC			= main.cpp A.cpp B.cpp C.cpp Base.cpp
OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re