/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_checks1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:25:05 by iobba             #+#    #+#             */
/*   Updated: 2023/01/07 17:05:41 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	is_rectangular(t_long *ptr)
{
	int	i;

	i = 0;
	while (ptr->map[i])
	{
		if (ft_strlen(ptr->map[i]) != ptr->width)
		{
			write(2, "Error\n", 6);
			write(2, "The map must be rectangular.\n", 29);
			freeing(ptr->map);
			freeing(ptr->cop);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	is_out_of5c(t_long *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if ((ptr->map[i][j] != '0' && ptr->map[i][j] != '1')
				&& (ptr->map[i][j] != 'C' && ptr->map[i][j] != 'E')
				&& ptr->map[i][j] != 'P' && ptr->map[i][j] != 'B')
			{
				write(2, "Error\n", 6);
				write (2, "The map can be composed of only 1 0 C P B E\n", 44);
				freeing(ptr->map);
				freeing(ptr->cop);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	clsdby_walls(t_long *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if ((ptr->map[0][j] != '1' || ptr->map[ptr->hght - 1][j] != '1')
			|| (ptr->map[i][0] != '1' || ptr->map[i][ptr->width - 1] != '1'))
			{
				write(2, "Error\n", 6);
				write (2, "The map must be surrounded by walls (1)\n", 40);
				freeing(ptr->map);
				freeing(ptr->cop);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_nof_needs(t_long *ptr, int nof_p, int nof_c, int nof_e)
{
	write (2, "Error\n", 6);
	if (nof_p != 1)
		write (2, "The map must contain 1 starting position.\n", 42);
	if (nof_c < 1)
		write (2, "The map must contain at least 1 collectible.\n", 45);
	if (nof_e != 1)
		write (2, "The map must contain 1 exit.\n", 29);
	freeing(ptr->map);
	freeing(ptr->cop);
	exit (EXIT_FAILURE);
}

void	found_needs(t_long *ptr)
{
	static int	i;
	int			j;
	static int	nof_e;
	static int	nof_p;

	ptr->nof_collect = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if (ptr->map[i][j] == 'P')
				nof_p++;
			else if (ptr->map[i][j] == 'C')
				ptr->nof_collect = ptr->nof_collect + 1;
			else if (ptr->map[i][j] == 'E')
				nof_e++;
			j++;
		}
		i++;
	}
	if (nof_p != 1 || nof_e != 1 || ptr->nof_collect < 1)
		check_nof_needs(ptr, nof_p, ptr->nof_collect, nof_e);
}
