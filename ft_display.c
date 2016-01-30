/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 22:06:34 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/30 22:50:21 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<ncurses.h>

void		ft_display(int col, int line)
{
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
}
