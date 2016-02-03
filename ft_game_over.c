/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:09:46 by jsoudier          #+#    #+#             */
/*   Updated: 2016/01/31 22:10:07 by jsoudier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	ft_end(int **box)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((j != 3 && box[i][j] == box[i][j + 1])
					|| (i != 3 && box[i][j] == box[i + 1][j]))
				return (0);
			if (i == 3 && j != 3 && box[i][j] == box[i][j + 1])
				return (0);
			if (j == 3 && i != 3 && box[i][j] == box[i + 1][j])
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}

int			ft_game_over(int **box)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (box[i][j] == WIN_VALUE)
				return (1);
			if (box[i][j] == 0)
				return (0);
		}
	}
	return (ft_end(box));
}
