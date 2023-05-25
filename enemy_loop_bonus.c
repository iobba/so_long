/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_loop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:03:45 by iobba             #+#    #+#             */
/*   Updated: 2023/01/08 14:53:41 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	death(t_long *sl)
{
	freeing(sl->map);
	write(1, "looozer!! the enemy got u !!\n", 29);
	exit(0);
}

void	enemy_move(t_long *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j])
		{
			if (sl->map[i][j] == 'B')
			{
				enemy_way(sl, &i, &j);
			}
			j++;
		}
		i++;
	}
}

int	enemy_f(t_long *sl)
{
	sl->iterater2++;
	if (sl->iterater2 == 100)
	{
		enemy_move(sl);
		sl->iterater2 = 0;
	}
	return (0);
}
