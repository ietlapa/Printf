/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ietlapa- <ietlapa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:58:41 by ietlapa-          #+#    #+#             */
/*   Updated: 2024/06/10 11:58:33 by ietlapa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long nbr)
{
	int		result;

	result = 0;
	if (!nbr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		result = ft_putstr("0x");
		result += ft_putptr(nbr);
	}
	return (result);
}

int	ft_putptr(unsigned long nb)
{
	int		re;
	char	*base;

	re = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		re += ft_putptr(nb / 16);
		re += ft_putptr(nb % 16);
	}
	else
		re += ft_putchar(base[nb % 16]);
	return (re);
}
