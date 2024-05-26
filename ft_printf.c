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

static int	ft_type(char c, va_list list);
static int	ft_print_help(const char *format, va_list list);

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	list;

	count = 0;
	va_start(list, format);
	count = ft_print_help(format, list);
	va_end(list);
	return (count);
}

static int	ft_print_help(const char *format, va_list list)
{
	int	i;
	int	err;
	int	count;

	i = 0;
	err = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			err = ft_type(format[i], list);
			if (err == -1)
				return (-1);
			count += err;
		}
		else
		{
			if (ft_putchar(format[i]) == -1)
				return (-1);
			count ++;
		}
		i++;
	}
	return (count);
}

static int	ft_type(char c, va_list list)
{
	int				err;
	unsigned long	nb;

	err = 0;
	if (c == 'c')
		err = ft_putchar(va_arg(list, int));
	else if (c == 's')
		err = ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		err = ft_putnbr((va_arg(list, int)), 10, DEC, &err);
	else if (c == 'X')
		err = ft_putnbr((va_arg(list, unsigned int)), 16, HEX, &err);
	else if (c == 'x')
		err = ft_putnbr((va_arg(list, unsigned int)), 16, HEX_LOW, &err);
	else if (c == 'p')
		err = ft_putnbr_p(va_arg(list, unsigned long), 16, HEX_LOW);
	else if (c == 'u')
		err = ft_putnbr(va_arg(list, unsigned int), 10, DEC, &err);
	else if (c == '%')
		err = ft_putchar(c);
	return (err);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("%d\n", ft_printf("%c\n", 'a'));
	printf("%d\n", printf("%c\n", 'a'));
	ft_printf("%d\n", ft_printf("%s\n", "hello"));
	printf("%d\n", printf("%s\n", "hello"));
	ft_printf("%d\n", ft_printf("%d\n", 42));
	ft_printf("%d\n", ft_printf("%i\n", 42));
	ft_printf("%d\n", ft_printf("%X\n", 42));
	ft_printf("%d\n", ft_printf("%x\n", 42));
	ft_printf("%d\n", ft_printf("%p\n", ""));
	printf("%d\n", printf("%p\n", ""));
	ft_printf("%d\n", ft_printf("%p\n", NULL));
	printf("%d\n", printf("%p\n", NULL));
	ft_printf("%d\n", ft_printf("%u\n", 42));
	ft_printf("%d\n", ft_printf("%%\n"));
	ft_printf("%d\n", ft_printf("Hello %cWorld\n", "hello"));
}
