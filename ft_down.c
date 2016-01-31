/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 09:03:32 by jsoudier          #+#    #+#             */
/*   Updated: 2016/01/31 09:53:10 by jsoudier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_merge_d(int **box)
{
	int	i;
	int	j;

	i = 4;
	while (--i >= 0)
	{
		j = 4;
		while(--j >= 0)
		{
			if (i != 0 && box[i][j] == box[i - 1][j] && box[i][j] != 0)
			{
				box[i][j] = box[i][j] + box[i][j];
				box[i - 1][j] = 0;
			}
		}
	}
}

static void	ft_refill(int **box, int tmp_i, int i ,int j)
{
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
		{
			if(box[i][j] != 0)
			{
				tmp_i = i;
				while (tmp_i < 3 && box[tmp_i + 1][j] == 0)
					tmp_i++;
				if (tmp_i != 3 && box[tmp_i + 1][j] != 0)
				{
					box[tmp_i][j] = box[i][j];
					if (i != tmp_i)
						box[i][j] = 0;
				}
				if (tmp_i == 3)
				{
					box[tmp_i][j] = box[i][j];
					if (i != (tmp_i))
						box[i][j] = 0;
				}
			}
		}
	}
}

int	**ft_down(int **box)
{
	int	i;
	int	j;
	int tmp_i;
	int counter;

	i = -1;
	counter = -1;
	j = 0;
	tmp_i = 0;
	while (++counter < 3)
	{
		ft_refill(box, tmp_i, i , j);
	}
	ft_merge_d(box);
	ft_refill(box, tmp_i, i , j);
	return (box);
}
