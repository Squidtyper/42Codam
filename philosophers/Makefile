# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/29 00:33:12 by lizhang       #+#    #+#                  #
#    Updated: 2023/06/01 17:13:37 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

SRC			= error.c philo_utils.c philo_actions.c access.c philo_info.c end.c\
			main.c check.c

OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus:
			@echo No bonus available

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		make all clean fclean bonus
