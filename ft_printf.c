/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ietlapa- <ietlapa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:05:52 by ietlapa-          #+#    #+#             */
/*   Updated: 2024/06/06 14:15:31 by ietlapa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
* Here we check which flag was passed, and in each case there is a 
specific * printing function and returns the number of characters printed 
*/

int	ft_formats(va_list arg, const char format)
{
	int		printlen;

	printlen = 0;
	if (format == 'd' || format == 'i')
		printlen = ft_putnbr(va_arg(arg, int));
	else if (format == 'c')
		printlen = ft_putchar(va_arg(arg, int));
	else if (format == 'u')
		printlen = ft_putunbr(va_arg(arg, unsigned int));
	else if (format == 's')
		printlen = ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
	{
		printlen = ft_putstr("0x");
		printlen += ft_putptr(va_arg(arg, void *));
	}
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'x' || format == 'X')
		printlen = ft_puthex(va_arg(arg, unsigned int), format);
	return (printlen);
}

//main function

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			i;
	int			result;

	i = 0;
	result = 0;
	va_start (arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += ft_formats(arg, str[i + 1]);
			i++;
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end (arg);
	return (result);
}
