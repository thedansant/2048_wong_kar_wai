/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 22:06:34 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 09:30:17 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

void		ft_displayn(int col, int line, int **tab)
{
	mvprintw(col / 8, line / 8, "%d", tab[0][0]);
	mvprintw(col * 3 / 8, line * 3 / 8, "%d", tab[1][1]);
	mvprintw(col * 5 / 8, line * 5 / 8, "%d", tab[2][2]);
	mvprintw(col * 7 / 8, line * 7 / 8, "%d", tab[3][3]);
	mvprintw(col * 3 / 8, line / 8, "%d", tab[1][0]);
	mvprintw(col / 8, line * 3 / 8, "%d", tab[0][1]);
	mvprintw(col * 5 / 8, line / 8, "%d", tab[2][0]);
	mvprintw(col * 7 / 8, line / 8, "%d", tab[3][0]);
	mvprintw(col / 8, line * 5 / 8, "%d", tab[0][2]);
	mvprintw(col / 8, line * 7 / 8, "%d", tab[0][3]);
	mvprintw(col * 3 / 8, line * 5 / 8, "%d", tab[1][2]);
	mvprintw(col * 3 / 8, line * 7 / 8, "%d", tab[1][3]);
	mvprintw(col * 5 / 8, line * 3 / 8, "%d", tab[2][1]);
	mvprintw(col * 5 / 8, line * 7 / 8, "%d", tab[2][3]);
	mvprintw(col * 7 / 8, line * 3 / 8, "%d", tab[3][1]);
	mvprintw(col * 7 / 8, line * 5 / 8, "%d", tab[3][2]);
}

void		ft_displayg(int col, int line)
{
	getmaxyx(stdscr, col, line);
	move(col - 1, 0);
	hline('-', line);
	move(0, line - 1);
	vline('|', col);
	move(0, 0);
	hline('-', line);
	vline('|', col);
	move(0, line / 2);
	vline('|', col);
	move(0, line / 4);
	vline('|', col);
	move(0, line - (line / 4));
	vline('|', col);
	move(col / 2, 0);
	hline('-', line);
	move(col / 4, 0);
	hline('-', line);
	move(col - (col / 4), 0);
	hline('-', line);
	ft_displayn(col, line);
}
