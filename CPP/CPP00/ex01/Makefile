# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/17 18:25:32 by lizhang       #+#    #+#                  #
#    Updated: 2023/01/14 19:06:42 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= phone_book
CC			= g++
RM			= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
SRC			= Contact.cpp PhoneBook.cpp main.cpp
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