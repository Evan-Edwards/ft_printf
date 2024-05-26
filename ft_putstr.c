#include "ft_printf.h"

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

