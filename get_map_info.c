/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:08:05 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 03:45:31 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	countlines(char *mappath)
{
	char	byte;
	int		linecount;
	int		fd;

	linecount = 0;
	fd = open(mappath, O_RDONLY);
	while ((read(fd, &byte, 1)) > 0)
	{
		if (byte == '\n')
		{
			linecount++;
		}
	}
	close(fd);
	return (linecount);
}

int	getlinesize(char *mappath)
{
	char	byte;
	int		fd;
	int		x;

	fd = open(mappath, O_RDONLY);
	x = 0;
	while (read(fd, &byte, 1))
	{
		if (byte == '\n')
			break ;
		else
		{
			x++;
		}
	}
	close(fd);
	return (x);
}

t_player	find_playerpos(char **map, char *mappath)
{
	t_player	p;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < countlines(mappath))
	{
		j = 0;
		while (j < getlinesize(mappath))
		{
			if (map[i][j] == 'P')
			{
				p.x = j;
				p.y = i;
			}
			j++;
		}
		i++;
	}
	return (p);
}
