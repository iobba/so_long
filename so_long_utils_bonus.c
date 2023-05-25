/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:35:43 by iobba             #+#    #+#             */
/*   Updated: 2023/01/06 20:14:43 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_error(t_long *ptr, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	freeing(ptr->map);
	freeing(ptr->cop);
	exit(EXIT_FAILURE);
}

void	freeing(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_strncmp(const char *ms1, const char *ms2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) ms1;
	s2 = (unsigned char *) ms2;
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb >= 0 && nb <= 9)
		ft_putchar_fd(nb + 48, fd);
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
	else if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nb * (-1), fd);
	}
}
