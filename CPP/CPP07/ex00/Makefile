# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/21 12:59:42 by lizhang       #+#    #+#                  #
#    Updated: 2023/06/11 12:49:27 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= whatever
CC			= g++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
INCLUDE		= -Iwhatever.hpp
SRC			= main.cpp
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