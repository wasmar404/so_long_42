/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:44:04 by wasmar            #+#    #+#             */
/*   Updated: 2024/06/23 09:40:30 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_num(int n)
{	
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		n = 147483648;
		count += 2;
	}
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putchar2(char c, char a)
{
	write(1, &c, 1);
	write(1, &a, 1);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = count_num(nb);
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb == -2147483648)
	{
		putchar2('-', '2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (i);
}
