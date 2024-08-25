/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:33:41 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 10:33:46 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main_helper(char *mappath)
{
	t_data1	*data;
	int		i;
	int		y;

	data = create_window(mappath);
	fill_player_pos_in_t_data1(data, mappath);
	data->countc = 0;
	data->count_moves = 0;
	data->countoc = count_c(data->map, mappath);
	i = countlines(mappath);
	y = getlinesize(mappath);
	data->lines = i;
	data->linesize = y;
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		data);
	maprun(data);
	mlx_loop(data->mlx_ptr);
	if (data->countc == 2)
		return (1);
	return (1);
}

void	first_error_to_check(char *str)
{
	int		fd;
	char	byte;
	int		x;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		write(1, "error", 5);
		exit(1);
	}
	x = 0;
	while ((read(fd, &byte, 1)) > 0)
	{
		x++;
	}
	if (x == 0)
	{
		write(1, "error1", 5);
		exit(1);
	}
	close(fd);
}

void	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i--;
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b')
	{
		write(1, "Error", 5);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int	error;

	check_ber(argv[1]);
	first_error_to_check(argv[1]);
	if (argc == 1)
	{
		ft_printf("error");
		return (0);
	}
	error = allerrors(argv[1]);
	if (error == 0)
		return (0);
	main_helper(argv[1]);
	return (0);
}
