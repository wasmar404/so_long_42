/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:33:19 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 10:33:21 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	checkpande(char **a, char *mappath)
{
	int	counte;
	int	countp;
	int	i;
	int	j;

	counte = 0;
	countp = 0;
	i = 0;
	j = 0;
	while (i < countlines(mappath))
	{
		j = 0;
		while (j < getlinesize(mappath))
		{
			if (a[i][j] == 'E')
				counte++;
			else if (a[i][j] == 'P')
				countp++;
			j++;
		}
		i++;
	}
	if (counte > 1 || countp > 1 || counte == 0 || countp == 0)
		return (0);
	return (1);
}

int	checkc(char **map, char *mappath)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < countlines(mappath))
	{
		j = 0;
		while (j < getlinesize(mappath))
		{
			if (map[i][j] == 'C')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	count_c(char **map, char *mappath)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (i < countlines(mappath))
	{
		j = 0;
		while (j < getlinesize(mappath))
		{
			if (map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	check_valid_char(char **map, char *mappath)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (j < getlinesize(mappath))
		{
			if (map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '0'
				&& map[i][j] != 'C' && map[i][j] != '1')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
