# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/01 17:20:47 by lizhang       #+#    #+#                  #
#    Updated: 2023/07/20 14:07:18 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= easy_find
CC			= c++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
INCLUDE		= -Ieasyfind.hpp
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

