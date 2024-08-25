/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maponscreen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:49:37 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 09:37:54 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_player_pos_in_t_data1(t_data1 *data, char *mappath)
{
	t_player	p;
	char		**map;

	map = array2d(mappath);
	p = find_playerpos(map, mappath);
	data->j = p.x;
	data->i = p.y;
	freemem(map, mappath);
}

t_data1	*set(t_data1	*data)
{
	int		h;
	int		w;

	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, " textures/wall.xpm",
			&w, &h);
	data->door_img = mlx_xpm_file_to_image(data->mlx_ptr, " textures/door.xpm",
			&w, &h);
	data->green_img = mlx_xpm_file_to_image(data->mlx_ptr,
			" textures/green.xpm", &w, &h);
	data->d_img = mlx_xpm_file_to_image(data->mlx_ptr, " textures/d.xpm",
			&w, &h);
	data->fox1_img = mlx_xpm_file_to_image(data->mlx_ptr, " textures/fox1.xpm",
			&w, &h);
	return (data);
}

t_data1	*create_window(char *mappath)
{
	t_data1	*data;
	char	**map;
	int		width;
	int		height;

	width = getlinesize(mappath);
	height = countlines(mappath);
	data = (t_data1 *)malloc(sizeof(t_data1));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width * 50, height * 50,
			"hi :)");
	if (!data->win_ptr)
		return (NULL);
	data = set(data);
	map = array2d(mappath);
	data->map = map;
	return (data);
}

int	maprun(t_data1 *dat)
{
	int	i;
	int	j;

	j = -1;
	while (++j < dat->lines)
	{
		i = -1;
		while (++i < dat->linesize)
		{
			if (dat->map[j][i] == '1')
				mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr,
					dat->wall_img, i * 50, j * 50);
			else if (dat->map[j][i] == 'C')
				mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr,
					dat->d_img, i * 50, j * 50);
			else if (dat->map[j][i] == 'E')
				mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr,
					dat->door_img, i * 50, j * 50);
			else
				mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr,
					dat->green_img, i * 50, j * 50);
		}
	}
	return (mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr,
			dat->fox1_img, dat->j * 50, dat->i * 50), 0);
}
