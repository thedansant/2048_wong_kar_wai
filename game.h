/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoudier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:15:44 by jsoudier          #+#    #+#             */
/*   Updated: 2016/01/31 12:19:25 by jsoudier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "libft/libft.h"
#include <curses.h>
#include <stdlib.h>
#include <time.h>
enum econst
{
	WIN_VALUE = 2048
};
typedef struct	s_case
{
	int n;
	int merge;
}				t_case;
int	**ft_rand(int **box, int start);
int	**ft_move(int **box, int ch);
int **ft_left(int **box);
int	**ft_right(int **box);
int	**ft_up(int **box);
int	**ft_down(int **box);
#endif