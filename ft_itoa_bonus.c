/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:11:31 by iobba             #+#    #+#             */
/*   Updated: 2023/01/08 16:19:41 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	int		l;
	char	*str;

	l = ft_len(nb);
	str = (char *) malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		str[0] = '-';
	str[l] = '\0';
	while (nb != 0)
	{
		l--;
		str[l] = ft_abs(nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
