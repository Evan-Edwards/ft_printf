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

void	ft_type(char c, va_list list, int *count);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i])
	{
		if (count < 0)
			return (-1);
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_type(format[i], list, &count);
			i++;
		}
		else
		{
			ft_putchar(format[i], &count);
			i++;
		}
	}
	va_end(list);
	return (count);
}

void	ft_type(char c, va_list list, int *count)
{
	unsigned long	n;

	n = 0;
	if (c == 'c')
		ft_putchar(va_arg(list, int), count);
	else if (c == 's')
		ft_putstr(va_arg(list, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr((va_arg(list, int)), 10, DEC, count);
	else if (c == 'X')
		ft_putnbr((va_arg(list, unsigned int)), 16, HEX, count);
	else if (c == 'x')
		ft_putnbr((va_arg(list, unsigned int)), 16, HEX_LOW, count);
	else if (c == 'p')
	{
		n = (unsigned long)(va_arg(list, void *));
		ft_putstr("0x", count);
		ft_putnbr_p(n, 16, HEX_LOW, count);
	}
	else if (c == 'u')
		ft_putnbr(va_arg(list, unsigned int), 10, DEC, count);
	else if (c == '%')
		ft_putchar(c, count);
	else
		(*count)--;
}
/*
#include <stdio.h>

int	main(void)
{
	//ft_printf("%d\n", ft_printf("%c\n", 'a'));
	//ft_printf("%d\n", ft_printf("%s\n", "hello"));
	//printf("%d\n", printf("%s\n", "hello"));
	//ft_printf("%d\n", ft_printf("%d\n", 42));
	//ft_printf("%d\n", ft_printf("%i\n", 42));
	//ft_printf("%d\n", ft_printf("%X\n", 42));
	//ft_printf("%d\n", ft_printf("%x\n", 42));
	//ft_printf("%d\n", ft_printf("%p\n", ""));
	//printf("%d\n", printf("%p\n", ""));
	//ft_printf("%d\n", ft_printf("%p\n", NULL));
	//printf("%d\n", printf("%p\n", NULL));
	//ft_printf("%d\n", ft_printf("%u\n", 42));
	//ft_printf("%d\n", ft_printf("%%\n"));
	//ft_printf("%d\n", ft_printf("Hello %cWorld\n", "hello"));

*/
