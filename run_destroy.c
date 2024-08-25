/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:44:59 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 03:46:30 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	on_destroy(t_data1 *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->d_img);
	mlx_destroy_image(data->mlx_ptr, data->door_img);
	mlx_destroy_image(data->mlx_ptr, data->fox1_img);
	mlx_destroy_image(data->mlx_ptr, data->green_img);
	mlx_destroy_image(data->mlx_ptr, data->wall_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
	exit(0);
	return (0);
}
