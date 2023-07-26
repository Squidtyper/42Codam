# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/01 17:20:47 by lizhang       #+#    #+#                  #
#    Updated: 2023/07/20 14:07:10 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= span
CC			= c++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
INCLUDE		= -ISpan.hpp
SRC			= main.cpp Span.cpp 
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

