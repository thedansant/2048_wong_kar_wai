/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 05:32:21 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 22:54:33 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_check_value(int value)
{
	while ((value % 2 == 0) && value > 1)
		value /= 2;
	if (value == 1)
		return (1);
	else
		return (0);
}

/*int		ft_check_min(int col, int line)
{
	if (col < 30 || line < 30)
		return (0);
}*/
