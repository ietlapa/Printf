/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ietlapa- <ietlapa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:15:30 by ietlapa-          #+#    #+#             */
/*   Updated: 2024/06/10 12:15:46 by ietlapa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nbr)
{
	int		result;

	result = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		result += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		result += ft_putnbr(nbr / 10);
		result += ft_putnbr(nbr % 10);
	}
	else
		result += ft_putchar(nbr + 48);
	return (result);
}

int	ft_putunbr(unsigned int nbr)
{
	unsigned int	result;

	result = 0;
	if (nbr > 9)
	{
		result += ft_putunbr(nbr / 10);
		result += ft_putunbr(nbr % 10);
	}
	else
		result += ft_putchar(nbr + 48);
	return (result);
}

int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
