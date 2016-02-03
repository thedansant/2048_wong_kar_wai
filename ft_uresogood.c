/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uresogood.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:51:41 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 23:21:43 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_uresogood(int **box)
{
	int		i;

	i = ft_game_over(box);
	if (i == -1)
	{
		endwin();
		ft_putstr("URE BAD\n");
		return (0);
	}
	return (2);
}
