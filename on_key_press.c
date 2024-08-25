/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 01:57:56 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 03:46:26 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	on_keypress(int keysym, t_data1 *data)
{
	if (keysym == 65307)
	{
		on_destroy(data);
	}
	else
	{
		on_keypress1(keysym, data);
		on_keypress2(keysym, data);
		on_keypress3(keysym, data);
		on_keypress4(keysym, data);
	}
	return (1);
}

void	on_keypress1(int keysym, t_data1 *data)
{
	if (keysym == 119)
	{
		if (((data->map[data->i - 1][data->j] == '0') || (data->map[data->i
					- 1][data->j] == 'P') || (data->map[data->i
					- 1][data->j] == 'C')) && ((data->i - 1) < data->lines)
			&& ((data->i - 1) >= 0))
		{
			data->i = data->i - 1;
			maprun(data);
			if (data->map[data->i][data->j] == 'C')
			{
				data->countc++;
				(data->map[data->i][data->j]) = '0';
			}
			data->count_moves++;
			ft_printf("%d\n", data->count_moves);
		}
		else if ((data->map[data->i - 1][data->j] == 'E'))
			on_keypress1_helper(data);
	}
}

void	on_keypress3(int keysym, t_data1 *data)
{
	if (keysym == 115)
	{
		if (((data->map[data->i + 1][data->j] == '0') || (data->map[data->i
					+ 1][data->j] == 'P') || (data->map[data->i
					+ 1][data->j] == 'C')) && ((data->i + 1) < data->lines)
			&& ((data->i + 1) >= 0))
		{
			data->i = data->i + 1;
			maprun(data);
			if (data->map[data->i][data->j] == 'C')
			{
				data->countc++;
				(data->map[data->i][data->j]) = '0';
			}
			data->count_moves++;
			ft_printf("%d\n", data->count_moves);
		}
		else if (data->map[data->i + 1][data->j] == 'E')
			on_keypress3_helper(data);
	}
}

void	on_keypress4(int keysym, t_data1 *data)
{
	if (keysym == 97)
	{
		if (((data->map[data->i][data->j - 1] == '0')
			|| (data->map[data->i][data->j - 1] == 'P')
				|| (data->map[data->i][data->j - 1] == 'C')) && ((data->j
					- 1) < data->linesize) && ((data->j - 1) >= 0))
		{
			data->j = data->j - 1;
			maprun(data);
			if (data->map[data->i][data->j] == 'C')
			{
				data->countc++;
				(data->map[data->i][data->j]) = '0';
			}
			data->count_moves++;
			ft_printf("%d\n", data->count_moves);
		}
		else if ((data->map[data->i][data->j - 1] == 'E'))
			on_keypress4_helper(data);
	}
}

void	on_keypress2(int keysym, t_data1 *data)
{
	if (keysym == 100)
	{
		if (((data->map[data->i][data->j + 1] == '0')
			|| (data->map[data->i][data->j + 1] == 'P')
				|| (data->map[data->i][data->j + 1] == 'C')) && ((data->j
					+ 1) < data->linesize) && ((data->j + 1) >= 0))
		{
			data->j = data->j + 1;
			maprun(data);
			if (data->map[data->i][data->j] == 'C')
			{
				data->countc++;
				(data->map[data->i][data->j]) = '0';
			}
			data->count_moves++;
			ft_printf("%d\n", data->count_moves);
		}
		else if (data->map[data->i][data->j + 1] == 'E')
			on_keypress2_helper(data);
	}
}
