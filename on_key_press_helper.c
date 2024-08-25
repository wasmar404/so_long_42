/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:14:15 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 03:46:19 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	on_keypress1_helper(t_data1 *data)
{
	if (data->countc == data->countoc)
	{
		data->i = data->i - 1;
		on_destroy(data);
	}
}

void	on_keypress3_helper(t_data1 *data)
{
	if (data->countc == data->countoc)
	{
		data->i = data->i + 1;
		on_destroy(data);
	}
}

void	on_keypress4_helper(t_data1 *data)
{
	if (data->countc == data->countoc)
	{
		data->j = data->j - 1;
		on_destroy(data);
	}
}

void	on_keypress2_helper(t_data1 *data)
{
	if (data->countc == data->countoc)
	{
		data->j = data->j + 1;
		on_destroy(data);
	}
}
