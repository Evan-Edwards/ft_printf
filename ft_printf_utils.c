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
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	int		i;
	char	*null;

	i = 0;
	null = "(null)";
	if (!s)
	{
		if (write (1, null, 6) == -1)
			*count = -1;
		else
			*count += 6;
	}
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
		ft_putnbr(nb / len, len, base, count);
	ft_putchar(base[nb % len], count);
}

void	ft_putnbr_p(unsigned long nb, int len, char *base, int *count)
{
	if (nb >= (unsigned long)len)
		ft_putnbr_p(nb / len, len, base, count);
	ft_putchar(base[nb % len], count);
}
