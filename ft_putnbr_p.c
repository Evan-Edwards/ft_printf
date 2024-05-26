#include "ft_printf.h"

static void  ft_help(unsigned long nb, unsigned long len, char *base, int *count)
{
    if (*count == -1)
        return ;
    if (nb >= len)
	    ft_help(nb / len, len, base, count);
	if (ft_putchar(base[nb % len]) == -1)
		*count = -1;
    else
        (*count)++;
}

int	ft_putnbr_p(unsigned long nb, unsigned long len, char *base)
{
	int count;

	count = 0;
    if (ft_putstr("0x") == -1)
        return (-1);
	count = 2;
    ft_help(nb, len, base, &count);
    return (count);
}