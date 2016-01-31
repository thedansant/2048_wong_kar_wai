/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 08:59:19 by jsoudier          #+#    #+#             */
/*   Updated: 2016/01/31 11:43:28 by jsoudier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_merge_r(int **box)
{
	int	i;
	int	j;

	i = 4;
	while (--i >= 0)
	{
		j = 4;
		while(--j >= 0)
		{
			if (j != 0 && box[i][j] == box[i][j - 1] && box[i][j] != 0)
			{
				box[i][j] = box[i][j] + box[i][j];
				box[i][j - 1] = 0;
			}
		}
	}
}

static void	ft_refill(int **box, int tmp_j, int i , int j)
{
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
		{
			if(box[i][j] != 0)
			{
				tmp_j = j;
				while (tmp_j < 4 && box[i][tmp_j + 1] == 0)
					tmp_j++;
				if (tmp_j != 4 && box[i][tmp_j + 1] != 0)
				{
					box[i][tmp_j] = box[i][j];
					if (j != tmp_j)
						box[i][j] = 0;
				}
				if (tmp_j == 4)
				{
					box[i][tmp_j - 1] = box[i][j];
					if (j != (tmp_j - 1))
						box[i][j] = 0;
				}
			}
		}
	}
}

int	**ft_right(int **box)
{
	int i;
	int	j;
	int tmp_j;
	int counter;

	i = -1;
	j = 0;
	tmp_j = 0;
	counter = -1;
	while (++counter < 3)
	{
		ft_refill(box, tmp_j, i , j);
	}
	ft_merge_r(box);
	ft_refill(box, tmp_j, i , j);
	return (box);
}
