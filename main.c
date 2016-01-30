/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:06:59 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/30 23:09:19 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

void	ft_display(int col, int line);

int		main(void)
{
	int		col;
	int		line;
	
	initscr();
	noecho();
	raw();
	getmaxyx(stdscr, col, line);
	ft_display(col, line);
	while (getch() == 410)
	{
		clear();
		getmaxyx(stdscr, col, line);
		ft_display(col, line);
		refresh();
	}
	getch();
	endwin();
	return (0);
}
