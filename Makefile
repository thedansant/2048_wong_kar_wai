# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 13:48:02 by jsoudier          #+#    #+#              #
#    Updated: 2016/01/31 12:57:52 by mbompoil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

O_SRC = main.o ft_display.o ft_left.o ft_right.o ft_down.o ft_move.o ft_up.o \

FLAG = -Wextra -Wall -Werror

INC = ./libft

all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -I $(INC)

$(NAME): $(O_SRC)
	make -C libft
	gcc -lncurses $(FLAG) -Llibft -lft -I $(INC) -o $(NAME) $(O_SRC)

clean:
	rm -rf $(O_SRC)

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: clean fclean all

.PHONY: all clean fclean re
