/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:29:51 by wasmar            #+#    #+#             */
/*   Updated: 2024/06/23 09:13:47 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hhexx_pointer(long unsigned int hex)
{
	int		x ;
	int		count;
	char	*a ;

	x = 0;
	count = 0;
	a = "0123456789abcdef";
	if (hex == 0)
		return (0);
	x = hex % 16;
	count = hhexx_pointer(hex / 16);
	if (x >= 0 && x < 16)
	{
		write(1, &a[x], 1);
		count++;
	}
	return (count);
}

int	ft_hexprintxpointer(long unsigned int hex)
{
	int	count;

	count = 0;
	if (hex == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = hhexx_pointer(hex);
	count += 2;
	return (count);
}
