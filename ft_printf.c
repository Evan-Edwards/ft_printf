/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:02:46 by eedwards          #+#    #+#             */
/*   Updated: 2024/05/14 14:02:49 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void    ft_type(char c, va_list list, int *count);
int ft_printf(const char *ex, ...)
{
    int     i;
    int     *count;
    char    *type;
    va_list list;

    i = 0;
    count = 0;
    va_start(list, ex);
    while (ex[i])
    {
        if (ex[i] == '%')
        {
            i++;
            ft_type(ex[i], list, count);
        }
        else
        {
            ft_putchar(ex[i], count);
            i++;
        }
    }
    return (count);
}

void    ft_type(char c, va_list list, int *count)
{
    unsigned long n;
    if (c == 'c')
        ft_putchar(va_arg(list, char), count);
    else if (c == 's')
        ft_putstr(va_arg(list, char *), count);
    else if (c == 'd' || c == 'i')
        ft_putnbr((long)(va_arg(list, int)), 10, dec, count);
    else if (c == 'X')
        ft_putnbr((long)(va_arg(list, unsigned int)), 16, hex, count);
    else if (c == 'x')
        ft_putnbr((long)(va_arg(list, unsigned int)), 16, hex_low, count);
    else if (c == 'p')
    {
        n = (unsigned long)(va_arg(list, void *));
        ft_putstr("0x", count);
        ft_putnbr(n, 16, hex, count);
    }
    else if (c == 'u')
        ft_putdec_uns(va_arg(list, unsigned int), 10, dec);
    else if (c == '%')
        ft_putchar(c, count);
    else
        count--;
}
