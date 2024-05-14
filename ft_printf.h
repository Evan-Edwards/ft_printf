/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:52:02 by eedwards          #+#    #+#             */
/*   Updated: 2024/05/14 14:54:03 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);

#endif
