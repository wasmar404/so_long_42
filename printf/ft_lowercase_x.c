/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:19:10 by wasmar            #+#    #+#             */
/*   Updated: 2024/07/31 08:32:52 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hhexx(unsigned int hex, char *a)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	if (hex == 0)
		return (0);
	x = hex % 16;
	count = hhexx(hex / 16, a);
	if (x >= 0 && x < 16)
	{
		write(1, &a[x], 1);
		count++;
	}
	return (count);
}

int	ft_hexprintx(unsigned int hex, char c)
{
	int		count;
	char	*a;

	if (hex == 0)
		return (write(1, "0", 1));
	if (c == 'x')
	{
		a = "0123456789abcdef";
		count = hhexx(hex, a);
	}
	else if (c == 'X')
	{
		a = "0123456789ABCDEF";
		count = hhexx(hex, a);
	}
	return (count);
}
