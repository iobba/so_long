/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:14:11 by iobba             #+#    #+#             */
/*   Updated: 2023/01/09 11:01:12 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	sl->coins = mlx_xpm_file_to_image(sl->mlx, "mgs/coins.xpm", &w, &h);
	sl->img_wall = mlx_xpm_file_to_image(sl->mlx, "mgs/walls.xpm", &w, &h);
	sl->img_bg = mlx_xpm_file_to_image(sl->mlx, "mgs/background.xpm", &w, &h);
	sl->img_plyr = mlx_xpm_file_to_image(sl->mlx, "mgs/player.xpm", &w, &h);
	sl->img_door = mlx_xpm_file_to_image(sl->mlx, "mgs/door.xpm", &w, &h);
	if (!sl->coins || !sl->img_wall || !sl->img_bg || !sl->img_plyr
		|| !sl->img_door)
		errrror(sl, "mgs/...xpm No such file or directory\n");
}
