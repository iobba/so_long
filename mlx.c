/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:20:27 by iobba             #+#    #+#             */
/*   Updated: 2023/01/08 15:47:12 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_long *sl, int i, int j)
{
	if (sl->map[i][j] == '0')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_bg, j * 64, i * 64);
	else if (sl->map[i][j] == 'E')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_door, j * 64, i * 64);
	else if (sl->map[i][j] == '1')
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_wall, j * 64, i * 64);
	else if (sl->map[i][j] == 'P')
	{
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_bg, j * 64, i * 64);
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_plyr, j * 64, i * 64);
	}
	else
	{
		mlx_put_image_to_window(sl->mlx, sl->win, sl->img_bg, j * 64, i * 64);
		mlx_put_image_to_window(sl->mlx, sl->win, sl->coins, j * 64, i * 64);
	}
}

void	get_image(t_long *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j])
		{
			put_img(sl, i, j);
			j++;
		}
		i++;
	}
}

int	ft_close(t_long *sl)
{
	freeing(sl->map);
	exit(0);
}

void	mlx_map(t_long *sl)
{
	sl->mlx = mlx_init();
	if (!sl->mlx)
		errrror(sl, "the initialization of mlx failed\n");
	sl->win = mlx_new_window(sl->mlx, sl->width * 64, sl->hght * 64, "so_long");
	init_img(sl);
	get_image(sl);
	sl->nof_moves = 0;
	mlx_hook(sl->win, 2, 0, &keys_func, sl);
	mlx_hook(sl->win, 17, 0, &ft_close, sl);
	mlx_loop (sl->mlx);
}
