/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ietlapa- <ietlapa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:29:13 by ietlapa-          #+#    #+#             */
/*   Updated: 2024/06/06 14:17:08 by ietlapa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list arg, const char format);
int		ft_putchar(int c);
int		ft_putunbr(unsigned int nbr);
int		ft_putnbr(int nbr);
int		ft_puthex(unsigned int nbr, const char dif);
int		ft_putstr(char *str);
int		ft_putptr(void *nbr);

#endif