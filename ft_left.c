/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 22:24:07 by jsoudier          #+#    #+#             */
/*   Updated: 2016/01/31 21:21:54 by jsoudier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		**ft_merge_l(int **box)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (j != 3 && box[i][j] == box[i][j + 1] && box[i][j] != 0)
			{
				box[i][j] = box[i][j] + box[i][j];
				box[i][j + 1] = 0;
				box[4][0] = box[4][0] + 1;
				box[4][1] = box[4][1] + box[i][j];
			}
		}
	}
	return (box);
}

static void		ft_compare(int **box, int tmp_j, int i, int j)
{
	if (tmp_j != 0 && box[i][tmp_j - 1] != 0)
	{
		box[i][tmp_j] = box[i][j];
		if (j != tmp_j)
		{
			box[4][0] = box[4][0] + 1;
			box[i][j] = 0;
		}
	}
	if (tmp_j == 0)
	{
		box[i][tmp_j] = box[i][j];
		if (j != (tmp_j))
		{
			box[4][0] = box[4][0] + 1;
			box[i][j] = 0;
		}
	}
}

static int		**ft_refill(int **box, int tmp_j, int i, int j)
{
	while (--(i) >= 0)
	{
		j = 4;
		while (--(j) >= 0)
		{
			if (box[i][j] != 0)
			{
				tmp_j = j;
				while (tmp_j > 0 && box[i][(tmp_j) - 1] == 0)
					(tmp_j)--;
				ft_compare(box, tmp_j, i, j);
			}
		}
	}
	return (box);
}

int				**ft_left(int **box)
{
	int		i;
	int		j;
	int		tmp_j;
	int		counter;

	i = 4;
	counter = -1;
	j = 0;
	tmp_j = 0;
	while (++counter < 3)
	{
		box = ft_refill(box, tmp_j, i, j);
	}
	box = ft_merge_l(box);
	ft_refill(box, tmp_j, i, j);
	return (box);
}
