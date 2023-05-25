/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:18:17 by iobba             #+#    #+#             */
/*   Updated: 2023/01/09 11:49:42 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_begin(char *str)
{
	write (2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	errrror(t_long *sl, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	freeing(sl->map);
	exit(EXIT_FAILURE);
}

void	init_img(t_long *sl)
{
	int	h;
	int	w;

	sl->coin1 = mlx_xpm_file_to_image(sl->mlx, "mgs/coin1.xpm", &w, &h);
	sl->coin2 = mlx_xpm_file_to_image(sl->mlx, "mgs/coin2.xpm", &w, &h);
	sl->coin3 = mlx_xpm_file_to_image(sl->mlx, "mgs/coin3.xpm", &w, &h);
	sl->coin4 = mlx_xpm_file_to_image(sl->mlx, "mgs/coin4.xpm", &w, &h);
	sl->coin5 = mlx_xpm_file_to_image(sl->mlx, "mgs/coin5.xpm", &w, &h);
	sl->coin6 = mlx_xpm_file_to_image(sl->mlx, "mgs/coin6.xpm", &w, &h);
	sl->img_wall = mlx_xpm_file_to_image(sl->mlx, "mgs/walls.xpm", &w, &h);
	sl->img_bg = mlx_xpm_file_to_image(sl->mlx, "mgs/background.xpm", &w, &h);
	sl->img_p = mlx_xpm_file_to_image(sl->mlx, "mgs/player.xpm", &w, &h);
	sl->img_c = mlx_xpm_file_to_image(sl->mlx, "mgs/cdoor.xpm", &w, &h);
	sl->img_o = mlx_xpm_file_to_image(sl->mlx, "mgs/odoor.xpm", &w, &h);
	sl->img_n = mlx_xpm_file_to_image(sl->mlx, "mgs/enemy.xpm", &w, &h);
	if (!sl->coin1 || !sl->coin2 || !sl->coin3 || !sl->coin4 || !sl->coin5
		|| !sl->coin6 || !sl->img_wall || !sl->img_bg || !sl->img_p
		|| !sl->img_c || !sl->img_o || !sl->img_n)
		errrror(sl, "mgs/...xpm No such file or directory\n");
}
