/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:10:35 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 03:45:00 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_all_lines_size(char **map, char *mappath)
{
	int	i;
	int	j;
	int	countt;
	int	temp;

	i = 0;
	j = 0;
	countt = 0;
	temp = getlinesize(mappath);
	while (map[j] != NULL)
	{
		countt = 0;
		i = 0;
		while (map[j][i] != '\n' && map[j][i] != '\0')
		{
			countt++;
			i++;
		}
		if (temp != countt)
			return (0);
		temp = countt;
		j++;
	}
	return (1);
}

int	checkmap(char **a, char *mappath)
{
	int	linesize;
	int	countline;
	int	i;
	int	j;

	linesize = getlinesize(mappath);
	countline = countlines(mappath);
	i = 0;
	j = 0;
	countline--;
	linesize--;
	while (j < countline)
	{
		i = 0;
		while (i < linesize)
		{
			if (a[0][i] != '1' || (a[countline][i] != '1'
				|| a[j][0] != '1' || a[j][linesize] != '1'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
