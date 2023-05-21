# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/12 12:42:23 by lizhang       #+#    #+#                  #
#    Updated: 2022/12/17 18:20:18 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone
CC			= g++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98 
SRC			= megaphone.cpp
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