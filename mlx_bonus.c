/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:20:27 by iobba             #+#    #+#             */
/*   Updated: 2023/01/08 16:10:07 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_long *sl, int i, int j)
{
	if (sl->map[i][j] == '0')
		mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_bg, j * 64, i * 64);
	else if (sl->map[i][j] == 'E')
	{
		mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_bg, j * 64, i * 64);
		if (!sl->nof_collect)
			mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_o, j * 64, i * 64);
		else
			mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_c, j * 64, i * 64);
	}
	else if (sl->map[i][j] == '1')
		mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_wall, j * 64, i * 64);
	else if (sl->map[i][j] == 'P' || sl->map[i][j] == 'B')
	{
		mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_bg, j * 64, i * 64);
		if (sl->map[i][j] == 'P')
			mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_p, j * 64, i * 64);
		else if (sl->map[i][j] == 'B')
			mlx_put_image_to_window(sl->mlx, sl->wn, sl->img_n, j * 64, i * 64);
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
	sl->wn = mlx_new_window(sl->mlx, sl->width * 64, sl->hght * 64, "so_long");
	sl->n_mvs = 0;
	sl->iterater = 0;
	sl->iterater2 = 0;
	init_img(sl);
	get_image(sl);
	mlx_hook(sl->wn, 2, 0, &keys_func, sl);
	mlx_hook(sl->wn, 17, 0, &ft_close, sl);
	mlx_loop_hook(sl->mlx, &l_func, sl);
	mlx_loop(sl->mlx);
}
