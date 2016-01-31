# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 13:48:02 by jsoudier          #+#    #+#              #
#    Updated: 2016/01/30 13:49:04 by jsoudier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

O_SRC = main.o

FLAG = -Wextra -Wall -Werror

INC = ./libft

all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -I $(INC)

$(NAME): $(O_SRC)
	make -C libft
	gcc $(FLAG) -Llibft -lft -I $(INC) -o $(NAME) $(O_SRC)

clean:
	rm -rf $(O_SRC)

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: clean fclean all

.PHONY: all clean fclean re
