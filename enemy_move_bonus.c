/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:46:52 by iobba             #+#    #+#             */
/*   Updated: 2023/01/08 13:50:35 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_right(t_long *sl, int i, int *j)
{
	if (sl->map[i][*j + 1] == 'P')
		death(sl);
	sl->map[i][*j] = '0';
	sl->map[i][*j + 1] = 'B';
	*j = *j + 1;
}

void	move_up(t_long *sl, int i, int j)
{
	if (sl->map[i - 1][j] == 'P')
		death(sl);
	sl->map[i][j] = '0';
	sl->map[i - 1][j] = 'B';
}

void	move_left(t_long *sl, int i, int j)
{
	if (sl->map[i][j - 1] == 'P')
		death(sl);
	sl->map[i][j] = '0';
	sl->map[i][j - 1] = 'B';
}

void	move_down(t_long *sl, int *i, int j)
{
	if (sl->map[*i + 1][j] == 'P')
		death(sl);
	sl->map[*i][j] = '0';
	sl->map[*i + 1][j] = 'B';
	*i = *i + 1;
}

void	enemy_way(t_long *sl, int *m, int *n)
{
	int	i;
	int	j;

	i = *m;
	j = *n;
	if (sl->map[i][j + 1] != '1' && sl->map[i][j + 1] != 'E'
		&& sl->map[i][j + 1] != 'C' && sl->map[i][j + 1] != 'B')
		move_right(sl, i, n);
	else if (sl->map[i - 1][j] != '1' && sl->map[i - 1][j] != 'E'
		&& sl->map[i - 1][j] != 'C' && sl->map[i - 1][j] != 'B')
		move_up(sl, i, j);
	else if (sl->map[i][j - 1] != '1' && sl->map[i][j - 1] != 'E'
		&& sl->map[i][j - 1] != 'C' && sl->map[i][j - 1] != 'B')
		move_left(sl, i, j);
	else if (sl->map[i + 1][j] != '1' && sl->map[i + 1][j] != 'E'
		&& sl->map[i + 1][j] != 'C' && sl->map[i + 1][j] != 'B')
		move_down(sl, m, j);
}
