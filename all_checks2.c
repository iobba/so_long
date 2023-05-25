/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:31:32 by iobba             #+#    #+#             */
/*   Updated: 2023/01/08 15:47:12 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	plyr_position(t_long *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->cop[i])
	{
		j = 0;
		while (ptr->cop[i][j])
		{
			if (ptr->cop[i][j] == 'P')
			{
				ptr->x = i;
				ptr->y = j;
				ptr->cop[i][j] = '_';
				return ;
			}
			j++;
		}
		i++;
	}
}

int	horisontal_line(t_long *ptr, int i, int j)
{
	int	n;
	int	k;

	k = 0;
	n = 1;
	while (ptr->cop[i][j + n] == '0' || ptr->cop[i][j + n] == 'C')
	{
		ptr->cop[i][j + n] = '_';
		n++;
		k++;
	}
	n = 1;
	while (ptr->cop[i][j - n] == '0' || ptr->cop[i][j - n] == 'C')
	{
		ptr->cop[i][j - n] = '_';
		n++;
		k++;
	}
	return (k);
}

int	vertical_line(t_long *ptr, int i, int j)
{
	int	m;
	int	k;

	m = 1;
	k = 0;
	while (ptr->cop[i + m][j] == '0' || ptr->cop[i + m][j] == 'C')
	{
		ptr->cop[i + m][j] = '_';
		m++;
		k++;
	}
	m = 1;
	while (ptr->cop[i - m][j] == '0' || ptr->cop[i - m][j] == 'C')
	{
		ptr->cop[i - m][j] = '_';
		m++;
		k++;
	}
	return (k);
}

void	visit_map(t_long *ptr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (ptr->cop[i])
	{
		j = 0;
		while (ptr->cop[i][j])
		{
			if (ptr->cop[i][j] == '_')
			{
				k = horisontal_line(ptr, i, j);
				k = k + vertical_line(ptr, i, j);
				if (k)
				{
					i = -1;
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

void	valid_path(t_long *ptr)
{
	static int	i;
	int			j;

	while (ptr->cop[i])
	{
		j = 0;
		while (ptr->cop[i][j])
		{
			if (ptr->cop[i][j] == 'C')
				map_error(ptr, "the path is not valid\n");
			if (ptr->cop[i][j] == 'E')
			{
				if ((ptr->cop[i][j + 1] != '_' && ptr->cop[i][j - 1] != '_')
					&& (ptr->cop[i + 1][j] != '_' && ptr->cop[i - 1][j] != '_'))
					map_error(ptr, "the path is not valid\n");
			}
			j++;
		}
		i++;
	}
}
