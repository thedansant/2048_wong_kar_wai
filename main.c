/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:06:59 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 06:14:32 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_displayg(int col, int line);

void	ft_exit()
{
	endwin();
	exit(0);
}

void		ft_init(void)
{
	int		col;
	int		line;

	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	ft_displayg(col, line);
	while (getch() != 27)
	{
		while (getch() == 410)
		{
			clear();
			getmaxyx(stdscr, col, line);
			if (col < 42 || line < 42)
				ft_exit();
			ft_displayg(col, line);
			sleep(1);
			refresh();
		}
	}
	ft_exit();
}

int		main()
{
	ft_init();
	return(0);
}
