/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:12:18 by jsoudier          #+#    #+#             */
/*   Updated: 2016/01/31 12:38:53 by jsoudier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	**ft_push(int **box, int ch)
{
	if (ch == KEY_RIGHT)
		box = ft_right(box);
	if (ch == KEY_LEFT)
		box = ft_left(box);
	if (ch == KEY_UP)
		box = ft_up(box);
	if (ch == KEY_DOWN)
		box = ft_down(box);
	return (box);
}

int			**ft_rand(int **box, int start)
{
	int i;
	int n;
	int pos;

	pos = 0;
	srand(time(0));
	n = 2 * ((rand() % 2) + 1);
	i = 0;
	while (i == 0 || box[pos / 4][pos % 4] != 0)
	{
		pos = rand() % 16;
		i++;
		if (box[pos / 4][pos % 4] == 0 && start == 1)
		{
			box[pos / 4][pos % 4] = n;
			i = 0;
			start = 0;
		}
	}
	n = 2 * ((rand() % 2) + 1);
	box[pos / 4][pos % 4] = n;
	return (box);
}

int			**ft_move(int **box, int ch)
{
	box = ft_push(box, ch);
	return (box);
}
