/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:10:11 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 09:33:01 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	allerrors(char *mappath)
{
	char	**map;

	map = array2d(mappath);
	if (error(map, mappath) == 0)
	{
		freemem(map, mappath);
		return (0);
	}
	else if (errorcheck1(map, mappath) == 0)
	{
		freemem(map, mappath);
		return (0);
	}
	else if (errorcheck(map, mappath) == 0)
	{
		freemem(map, mappath);
		return (0);
	}
	freemem(map, mappath);
	return (1);
}
