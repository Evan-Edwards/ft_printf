/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:38:51 by eedwards          #+#    #+#             */
/*   Updated: 2024/05/14 15:38:54 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	int	err;

	err = write(1, &c, 1);
	if (err == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	if (!s)
		*count = -1;
	return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count);
		if (*count == -1)
			return ;
		i++;
	}
}

void	ft_putnbr(long nb, int len, char *base, int *count)
{
	if (nb < 0)
	{
		ft_putchar('-', count);
		if (*count == -1)
			return ;
		nb *= -1;
	}
	if (nb >= len)
	{
		ft_putnbr(len, nb / len, base, count);
		ft_putnbr(len, nb % len, base, count);
	}
	else
		ft_putchar(base[len], count);
}
