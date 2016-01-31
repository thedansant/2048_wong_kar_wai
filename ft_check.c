/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 05:32:21 by mbompoil          #+#    #+#             */
/*   Updated: 2016/01/31 06:14:17 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check_key()
{
	 int     ch;
	 ch = getch();
	 if (ch == KEY_LEFT)
		 ft_qwqqdqw();
	 else if (ch == KEY_RIGHT)
		 ft_sfafqw();
	  else if (ch == KEY_UP)
		  ft_efqfqke();
	  else if (ch == KEY_DOWN)
		  ft_qfkqpfk();
}

void	ft_check_value(int	value)
{
	while ((value % 2 == 0) && value > 1)
		value /= 2;
	if (value == 1)
		return ;
	else
		ft_exit();
}
