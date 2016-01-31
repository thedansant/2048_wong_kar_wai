/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 22:06:34 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 06:14:27 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<ncurses.h>

void		ft_displayn(int col, int line)
{
	mvprintw(col / 8, line / 8, "%d", 0);
	mvprintw(col * 3 / 8, line * 3 / 8, "%d", 0);
	mvprintw(col * 5 / 8, line * 5 / 8, "%d", 0);
	mvprintw(col * 7 / 8, line * 7 / 8, "%d", 0);
	mvprintw(col * 3 / 8, line / 8, "%d", 0);
	mvprintw(col / 8, line * 3 / 8, "%d", 0);
	mvprintw(col * 5 / 8, line / 8, "%d", 0);
	mvprintw(col * 7 / 8, line / 8, "%d", 0);
	mvprintw(col / 8, line * 5 / 8, "%d", 0);
	mvprintw(col / 8, line * 7 / 8, "%d", 0);
	mvprintw(col * 3 / 8, line * 5 / 8, "%d", 0);
	mvprintw(col * 3 / 8, line * 7 / 8, "%d", 0);
	mvprintw(col * 5 / 8, line * 3 / 8, "%d", 0);
	mvprintw(col * 5 / 8, line * 7 / 8, "%d", 0);
	mvprintw(col * 7 / 8, line * 3 / 8, "%d", 0);
	mvprintw(col * 7 / 8, line * 5 / 8, "%d", 0);
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
	move(col - (col /4), 0);
	hline('-', line);
	ft_displayn(col, line);
}
