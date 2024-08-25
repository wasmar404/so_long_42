/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:17:18 by wasmar            #+#    #+#             */
/*   Updated: 2024/06/23 09:28:56 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	helper(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putcharr(va_arg(arg, int));
	else if (c == 's')
		len = ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len = ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'X')
		len = ft_hexprintx(va_arg(arg, int), c);
	else if (c == 'x')
		len = ft_hexprintx(va_arg(arg, int), c);
	else if (c == '%')
		len = percent(c);
	else if (c == 'p')
		len = ft_hexprintxpointer(va_arg(arg, long unsigned int));
	return (len);
}

int	in_set(char c, char *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (c == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		length;
	va_list	arg;

	va_start (arg, s);
	length = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && in_set(s[i + 1], "cspdiuxX%"))
		{
			length += helper(arg, s[i + 1]);
			i++;
		}
		else
		{
			length += ft_putcharr(s[i]);
		}
		i++;
	}
	va_end(arg);
	return (length);
}
