/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ietlapa- <ietlapa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:53:54 by ietlapa-          #+#    #+#             */
/*   Updated: 2024/06/06 14:10:06 by ietlapa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, const char dif)
{
	int		result;
	char	*base;

	result = 0;
	if (dif == 'x')
		base = "0123456789abcdef";
	else if (dif == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0)
	{
		result += ft_putchar('0');
		return (result);
	}
	if (nbr >= 16)
		result += ft_puthex((nbr / 16), dif);
	result += ft_putchar(base[nbr % 16]);
	return (result);
}

/*
int	main()
{
	unsigned int x = 20090;

	ft_printf("el hexadecimale es %x\n", x);
	return (0);
}*/
