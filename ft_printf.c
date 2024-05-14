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
    if (c == 'c')
        ft_putchar(va_arg(list, char));
    else if (c == 's')
        ft_putstr(va_arg(list, char *));
    else if (c == 'd' || c == 'i')
        ft_putnbr(va_arg(list, int));
    else if (c == 'x' || c == 'X')
        ft_puthex(va_arg(list, unsigned int));
    else if (c == 'p')
        ft_puthex_v(va_arg(list, void *));
    else if (c == 'u')
        ft_putdec_uns(va_arg(list, unsigned int));
    else if (c == '%')
        ft_putchar_fd(c, 1);

}