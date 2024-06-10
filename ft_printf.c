/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ietlapa- <ietlapa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:05:52 by ietlapa-          #+#    #+#             */
/*   Updated: 2024/06/10 14:18:29 by ietlapa-         ###   ########.fr       */
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
		printlen = ft_printptr(va_arg(arg, unsigned long));
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
/*
int	main ()
{
	int num = 23;
	int c = 'a';
	int c2 = '\0';
	char *s = "world!";
	char *s2 = NULL;
 	void *p = &num;
	void *p2 = 0;
	long int d = -36;
	long int d2 = 36;
	long int d3 = 0;
	unsigned int u = 344;
	unsigned int u2 = 0;
	unsigned int x = 165;
	unsigned int x2 = -165;
	unsigned int x3 = 0;
	ft_printf("---- format c ----\n");
	ft_printf("mi print = %c\n", c);
	printf("printf = %c\n", c);
	ft_printf("mi print = %c\n", c2);
	printf("printf = %c\n\n", c2);
	ft_printf("---- format s ----\n");
	ft_printf("mi print = %s\n", s);
	printf("printf = %s\n", s);
	ft_printf("mi print = %s\n", s2);
	printf("printf = %s\n\n", s2);
	ft_printf("---- format p ----\n");
 	ft_printf("mi print = %p\n", p);
 	printf("printf = %p\n", p);
 	ft_printf("mi print = %p\n", p2);
 	printf("printf = %p\n\n", p2);
	ft_printf("---- format d-i ----\n");
	ft_printf("mi print = %d\n", d);
	printf("printf = %ld\n", d);
	ft_printf("mi print = %d\n", d2);
	printf("printf = %ld\n", d2);
	ft_printf("mi print = %d\n", d3);
	printf("printf = %ld\n\n", d3);
	ft_printf("---- format u ----\n");
	ft_printf("mi print = %u\n", u);
	printf("printf = %u\n", u);
	ft_printf("mi print = %u\n", u2);
	printf("printf = %u\n\n", u2);	
	ft_printf("---- format X-x ----\n");
	ft_printf("mi print = %x\n", x);
	printf("printf = %x\n", x);
	ft_printf("mi print = %x\n", x2);
	printf("printf = %x\n", x2);
	ft_printf("mi print = %x\n", x3);
	printf("printf = %x\n\n", x3);
	return (0);
}
*/


int main (void)
{
	int n;
	int *p = &n;
	int	i;
	int j;

	i = ft_printf("olakase    %p, %s, %s,   %%, %c, %i, 658 %u, %X\n", p, "", "hola", 'W', -420, 0, 1565);
	j = printf("olakase    %p, %s, %s,   %%, %c, %i, 658 %u, %X\n", p, "", "hola", 'W', -420, 0, 1565);
	ft_printf("%i = %i", i, j);
	return (0);
}

