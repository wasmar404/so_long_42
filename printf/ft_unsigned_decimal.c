/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:16:52 by wasmar            #+#    #+#             */
/*   Updated: 2024/06/22 16:40:13 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_numm(unsigned int n)
{	
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_putcharw(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_putnbr_unsigned(unsigned int nb)
{
	int	i;

	i = count_numm(nb);
	if (nb == 0)
		return (write (1, "0", 1));
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
	{
		ft_putcharw(nb + '0');
	}
	return (i);
}
