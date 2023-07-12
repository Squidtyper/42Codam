# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lizhang <lizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/18 21:21:47 by lizhang       #+#    #+#                  #
#    Updated: 2022/03/18 17:02:57 by lizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
INCLUDE		= -Ilibft

SRC			= srcs/ft_printf.c \
			  srcs/ft_writechar.c \
			  srcs/ft_writestd.c \
			  srcs/ft_writestr.c \
			  srcs/ft_writehex.c \
			  srcs/ft_writex.c \
			  srcs/ft_writeui.c \
			  srcs/ft_writenull.c \
			  srcs/ft_writeint.c \
			  srcs/ft_writevoid.c \

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
				$(MAKE) -C libft
				cp libft/libft.a $(NAME)
				ar rc $(NAME) $(OBJ)

%.o:%.c
				$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<

bonus:
			$(MAKE) 
			@echo no bonus available

clean:
				$(RM) $(OBJ) && cd libft && $(MAKE) clean

fclean:		clean 
				$(RM) $(NAME) && cd libft && $(MAKE) fclean 

re:			fclean $(NAME)

.PHONY:		make all clean fclean re bonus
