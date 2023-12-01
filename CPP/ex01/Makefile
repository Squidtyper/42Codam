# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/14 12:50:07 by lizhang       #+#    #+#                  #
#    Updated: 2023/08/17 15:51:47 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= RPN
CC			= c++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++11
INCLUDE		= -IRPN.hpp
SRC			= main.cpp RPN.cpp
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