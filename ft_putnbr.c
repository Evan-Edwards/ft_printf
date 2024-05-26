#include "ft_printf.h"

int	ft_putnbr(long nb, int len, char *base, int *count)
{
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		(*count)++;
		nb *= -1;
	}
	if (nb >= len)
	{
		if (ft_putnbr(nb / len , len, base, count) == -1)
			return (-1);
	}
	if (ft_putchar(base[nb % len]) == -1)
		return (-1);
	(*count)++;
	return (*count);
}