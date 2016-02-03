/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:15:44 by jsoudier          #+#    #+#             */
/*   Updated: 2016/01/31 23:05:50 by jsoudier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "libft/libft.h"
# include <curses.h>
# include <stdlib.h>
# include <time.h>

enum	e_const
{
	WIN_VALUE = 2048
};
int				**ft_rand(int **box, int start);
int				**ft_move(int **box, int ch);
int				**ft_left(int **box);
int				**ft_right(int **box);
int				**ft_up(int **box);
int				**ft_down(int **box);
void			ft_displayg(int col, int line, int **box);
int				ft_check_min(int col, int line);
int				ft_check_value(int value);
int				ft_game_over(int **box);
int				ft_uresogood(int **box);
#endif
