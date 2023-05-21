# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/17 15:28:22 by lizhang       #+#    #+#                  #
#    Updated: 2023/01/27 11:37:40 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= account
CC			= g++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 
SRC			= Account.cpp tests.cpp
OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re