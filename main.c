/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:06:59 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 12:28:21 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_displayg(int col, int line, int **box);

void	ft_exit(void)
{
	endwin();
	exit(0);
}

void	ft_init(int **box)
{
	int		col;
	int		line;
	int		ch;

	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	while ((ch = getch()) != 27)
	{
		clear();
		ft_displayg(col, line, box);
		box = ft_move(box, ch);
		box = ft_rand(box, 0);
		refresh();
		while (getch() == 410)
		{
			clear();
			getmaxyx(stdscr, col, line);
			if (col < 30 || line < 30)
				ft_exit();
			ft_displayg(col, line, box);
			sleep(1);
			refresh();
		}
	}
	ft_exit();
}

int		main(void)
{
	int	**box;
	int	i;

	i = -1;
	box = ft_memalloc(sizeof(int*) * 4);
	while (++i < 4)
		box[i] = ft_memalloc(sizeof(int) * 4);
	box = ft_rand(box, 1);
	ft_init(box);
	return (0);
}
