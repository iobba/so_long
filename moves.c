/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:23:10 by iobba             #+#    #+#             */
/*   Updated: 2023/01/06 18:55:26 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_up(t_long *sl)
{
	if (sl->map[sl->x - 1][sl->y] != '1')
	{
		if (sl->map[sl->x - 1][sl->y] == 'C')
			sl->nof_collect--;
		if (sl->map[sl->x - 1][sl->y] == 'E')
		{
			if (sl->nof_collect != 0)
				return ;
			freeing(sl->map);
			write(1, "congra!! you won !!\n", 20);
			exit(0);
		}
		sl->nof_moves++;
		sl->map[sl->x][sl->y] = '0';
		sl->x--;
		sl->map[sl->x][sl->y] = 'P';
		get_image(sl);
		ft_putnbr_fd(sl->nof_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_to_down(t_long *sl)
{
	if (sl->map[sl->x + 1][sl->y] != '1')
	{
		if (sl->map[sl->x + 1][sl->y] == 'C')
			sl->nof_collect--;
		if (sl->map[sl->x + 1][sl->y] == 'E')
		{
			if (sl->nof_collect != 0)
				return ;
			freeing(sl->map);
			write(1, "congra!! you won !!\n", 20);
			exit(0);
		}
		sl->nof_moves++;
		sl->map[sl->x][sl->y] = '0';
		sl->x++;
		sl->map[sl->x][sl->y] = 'P';
		get_image(sl);
		ft_putnbr_fd(sl->nof_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_to_right(t_long *sl)
{
	if (sl->map[sl->x][sl->y + 1] != '1')
	{
		if (sl->map[sl->x][sl->y + 1] == 'C')
			sl->nof_collect--;
		if (sl->map[sl->x][sl->y + 1] == 'E')
		{
			if (sl->nof_collect != 0)
				return ;
			freeing(sl->map);
			write(1, "congra!! you won !!\n", 20);
			exit(0);
		}
		sl->nof_moves++;
		sl->map[sl->x][sl->y] = '0';
		sl->y++;
		sl->map[sl->x][sl->y] = 'P';
		get_image(sl);
		ft_putnbr_fd(sl->nof_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_to_left(t_long *sl)
{
	if (sl->map[sl->x][sl->y - 1] != '1')
	{
		if (sl->map[sl->x][sl->y - 1] == 'C')
			sl->nof_collect--;
		if (sl->map[sl->x][sl->y - 1] == 'E')
		{
			if (sl->nof_collect != 0)
				return ;
			freeing(sl->map);
			write(1, "congra!! you won !!\n", 20);
			exit(0);
		}
		sl->nof_moves++;
		sl->map[sl->x][sl->y] = '0';
		sl->y--;
		sl->map[sl->x][sl->y] = 'P';
		get_image(sl);
		ft_putnbr_fd(sl->nof_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	keys_func(int key, t_long *sl)
{
	if (key == 53)
	{
		freeing(sl->map);
		exit(0);
	}
	if (key == 123 || key == 0)
		move_to_left(sl);
	if (key == 124 || key == 2)
		move_to_right(sl);
	if (key == 125 || key == 1)
		move_to_down(sl);
	if (key == 126 || key == 13)
		move_to_up(sl);
	return (0);
}
