/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:01:43 by jsoudier          #+#    #+#             */
/*   Updated: 2016/01/31 12:03:14 by jsoudier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_merge_u(int **box)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
		{
			if (i != 3 && box[i][j] == box[i + 1][j] && box[i][j] != 0)
			{
				box[i][j] = box[i][j] + box[i][j];
				box[i + 1][j] = 0;
			}
		}
	}
}

static void	ft_refill(int **box, int tmp_i, int i , int j)
{
	while (--i >= 0)
	{
		j = 4;
		while(--j >= 0)
		{
			if(box[i][j] != 0)
			{
				tmp_i = i;
				while (tmp_i > 0 && box[tmp_i - 1][j] == 0)
					tmp_i--;
				if (tmp_i != 0  && box[tmp_i - 1][j] != 0)
				{
					box[tmp_i][j] = box[i][j];
					if (i != tmp_i)
						box[i][j] = 0;
				}
				if (tmp_i == 0)
				{
					box[tmp_i][j] = box[i][j];
					if (i != (tmp_i))
						box[i][j] = 0;
				}
			}
		}
	}
}

int	**ft_up(int **box)
{
	int	i;
	int	j;
	int	tmp_i;
	int counter;

	i = 4;
	j = 0;
	tmp_i = 0;
	counter = -1;
	while (++counter < 3)
	{
		ft_refill(box, tmp_i, i , j);
	}
	ft_merge_u(box);
	ft_refill(box, tmp_i, i , j);
	return (box);
}
