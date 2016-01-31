/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:06:59 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 22:59:38 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		ft_scrinit(void)
{
	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
}

static void		ft_init(int **box, int ch)
{
	int		col;
	int		line;

	ft_scrinit();
	getmaxyx(stdscr, col, line);
	ft_displayg(col, line, box);
	while ((ch = getch()) != 27)
	{
		refresh();
		clear();
	//	ft_check_min(col, line);
		box = ft_move(box, ch);
		if (box[4][0] > 0)
			box = ft_rand(box, 0);
		box[4][0] = 0;
		ft_uresogood(box);
		ft_displayg(col, line, box);
		if (ch == 410)
		{
			clear();
			getmaxyx(stdscr, col, line);
			ft_displayg(col, line, box);
			refresh();
		}
	}
}

int			main(void)
{
	int	**box;
	int	i;
	int ch;

	ch = 0;
	i = -1;
	if (ft_check_value(WIN_VALUE) == 1)
	{
		box = ft_memalloc(sizeof(int*) * 8);
		while (++i < 6)
			box[i] = ft_memalloc(sizeof(int) * 8);
		box = ft_rand(box, 1);
		ft_init(box, ch);
	}
	clear();
	ft_putstr("1 + 1 ?\n");
	return (0);
}
