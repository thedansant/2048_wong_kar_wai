/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:06:59 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 14:44:51 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		ft_exit(void)
{
	endwin();
	exit(0);
}

static void		ft_scrinit(void)
{
	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
}

static void		ft_init(int **box)
{
	int		col;
	int		line;
	int		ch;

	ft_scrinit();
	getmaxyx(stdscr, col, line);
	ft_displayg(col, line, box);
	while ((ch = getch()) != 27)
	{
		refresh();
		clear();
		box = ft_move(box, ch);
		box = ft_rand(box, 0);
		ft_displayg(col, line, box);
		while (ch == 410)
		{
			clear();
			getmaxyx(stdscr, col, line);
			if (col < 30 || line < 30)
				ft_exit();
			ft_displayg(col, line, box);
			usleep(200000);
			refresh();
		}
	}
}

int				main(void)
{
	int	**box;
	int	i;

	i = -1;
	box = ft_memalloc(sizeof(int*) * 4);
	while (++i < 4)
		box[i] = ft_memalloc(sizeof(int) * 4);
	box = ft_rand(box, 1);
	ft_init(box);
	ft_exit();
	return (0);
}
