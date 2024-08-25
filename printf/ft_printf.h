/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:31:08 by wasmar            #+#    #+#             */
/*   Updated: 2024/06/23 09:53:27 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int				ft_printf(const char *s, ...);
int				helper(va_list arg, char c);
int				ft_putstr(char *str);
int				ft_hexprintxpointer(long unsigned int hex);
int				t_hexprintx(unsigned int hex, char c);
int				ft_putcharr(char c);
int				hexcount(int hex);
int				percent(char c);
int				ft_putnbr(int nb);
int				ft_hexprintx(unsigned int hex, char c);
unsigned int	ft_putnbr_unsigned(unsigned int nb);
#endif
