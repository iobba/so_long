/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_coins_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:31 by iobba             #+#    #+#             */
/*   Updated: 2023/01/08 16:20:16 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_nofmvs(t_long *sl)
{
	sl->str = ft_itoa(sl->n_mvs);
	mlx_string_put(sl->mlx, sl->wn, 0, 0, 0x0000FF00, "moves: ");
	mlx_string_put(sl->mlx, sl->wn, 64, 0, 0x0000FF00, sl->str);
	free(sl->str);
}

void	found_c(t_long *sl, int i, int j)
{
	if (sl->map[i][j] == 'C')
	{
		mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_bg, j * 64, i * 64);
		mlx_put_image_to_window(sl->mlx, sl->wn, g(sl), j * 64, i * 64);
	}
}

void	*g(t_long *sl)
{
	if (sl->iterater > 60)
		sl->iterater = 0;
	if (sl->iterater <= 10)
		return (sl->coin1);
	else if (sl->iterater > 10 && sl->iterater <= 20)
		return (sl->coin2);
	else if (sl->iterater > 20 && sl->iterater <= 30)
		return (sl->coin3);
	else if (sl->iterater > 30 && sl->iterater <= 40)
		return (sl->coin4);
	else if (sl->iterater > 40 && sl->iterater <= 50)
		return (sl->coin5);
	return (sl->coin6);
}

int	l_func(t_long *sl)
{
	int	i;
	int	j;

	i = 0;
	sl->iterater++;
	mlx_clear_window(sl->mlx, sl->wn);
	get_image(sl);
	put_nofmvs(sl);
	enemy_f(sl);
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j])
		{
			found_c(sl, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
