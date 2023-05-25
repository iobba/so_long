/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:21:04 by iobba             #+#    #+#             */
/*   Updated: 2023/01/09 12:10:44 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_map(t_long *ptr, char *av1)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av1, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line && ft_strchr_nl(line))
			line[(ft_strlen(line) - 1)] = '\0';
		if (!line)
			break ;
		ptr->cop[i] = malloc((ft_strlen(line) + 1) * sizeof(char));
		if (!ptr->cop[i])
			exit(EXIT_FAILURE);
		ptr->map[i] = line;
		ft_strlcpy(ptr->cop[i], line, ft_strlen(line) + 1);
		i++;
	}
	ptr->map[i] = NULL;
	ptr->cop[i] = NULL;
}

void	no_nline(char *line, char *last_line)
{
	if (!last_line)
	{
		write (2, "ERROR: invalid map\n", 19);
		exit(EXIT_FAILURE);
	}
	if (ft_strchr_nl(last_line))
	{
		free(last_line);
		free(line);
		write (2, "ERROR: invalid map\n", 19);
		exit (EXIT_FAILURE);
	}
}

int	nof_lines(char	*av1)
{
	int			fd;
	static int	i;
	char		*last_line;
	char		*line;

	fd = open(av1, O_RDONLY);
	if (fd < 0)
		error_begin("ERROR: failed opening\n");
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			no_nline(line, last_line);
			break ;
		}
		if (i)
			free(last_line);
		last_line = line;
		i++;
	}
	close(fd);
	free(last_line);
	return (free(line), i);
}

void	get_check_map(t_long *ptr, char *av1)
{
	int	i;

	i = nof_lines(av1);
	ptr->map = (char **)malloc((i + 1) * sizeof(char *));
	ptr->cop = (char **)malloc((i + 1) * sizeof(char *));
	if (ptr->map == NULL || ptr->cop == NULL)
		exit(EXIT_FAILURE);
	fill_map(ptr, av1);
	ptr->width = ft_strlen(ptr->map[0]);
	ptr->hght = i;
	is_rectangular(ptr);
	is_out_of5c(ptr);
	clsdby_walls(ptr);
	found_needs(ptr);
	player_position(ptr);
	visit_map(ptr);
	valid_path(ptr);
	freeing(ptr->cop);
}

int	main(int ac, char **av)
{
	t_long	ptr;

	if (ac == 2)
	{
		if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".ber", 5))
		{
			write(2, "Error\n", 6);
			write (2, "The map should be in format *.ber\n", 34);
			exit(EXIT_FAILURE);
		}
		get_check_map(&ptr, av[1]);
		mlx_map(&ptr);
	}
	else
		write(2, "arguments should be 2\n", 22);
	return (0);
}
