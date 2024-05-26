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

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
	{
		return (-1);
	}
	return (1);
}

int	ft_putstr(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		count ++;
		i++;
	}
	return (count);
}

int	ft_putnbr(long nb, int len, char *base)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count ++;
		nb *= -1;
	}
	while (nb >= len)
	{
		if (ft_putchar(base[nb % len]) == -1)
			return (-1);
		count ++;
		nb = nb / len;
	}
	if (ft_putchar(base[nb % len]) == -1)
		return (-1);
	count ++;
	return (count);
}

int	ft_putnbr_p(void *ptr, unsigned long len, char *base)
{
	int				count;
	unsigned long	nb;

	nb = (unsigned long)(ptr);
	if (ft_putstr("0x") == -1)
		return (-1);
	count = 2;
	while (nb >= len)
	{
		if (ft_putchar(base[nb % len]) == -1)
			return (-1);
		count ++;
		nb = nb / len;
	}
	if (ft_putchar(base[nb % len]) == -1)
		return (-1);
	count ++;
	return (count);
}
