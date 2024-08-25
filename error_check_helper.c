/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:33:25 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 10:33:26 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	errorcheck_helper(char **map1, char*mappath)
{
	ft_printf("Error");
	freemem(map1, mappath);
	exit(1);
}

int	errorcheck(char **map, char *mappath)
{
	t_player	start;
	t_count		c;
	int			j;
	char		**map1;

	map1 = array2d(mappath);
	j = count_c(map, mappath);
	c.t_counte = 0;
	c.t_countc = 0;
	start = find_playerpos(map, mappath);
	check_path_to_coin(map, (t_player){getlinesize(mappath),
		countlines(mappath)},
		start, &c);
	check_path_to_exit(map1, (t_player){getlinesize(mappath),
		countlines(mappath)},
		start, &c);
	if (j != c.t_countc)
		errorcheck_helper(map1, mappath);
	else if (c.t_counte != 1)
		errorcheck_helper(map1, mappath);
	freemem(map1, mappath);
	return (1);
}

int	error(char **map, char *mappath)
{
	if (!check_valid_char(map, mappath))
	{
		ft_printf("Error1");
		return (0);
	}
	else if (!check_all_lines_size(map, mappath))
	{
		ft_printf("Error");
		return (0);
	}
	return (1);
}

int	errorcheck1(char **map, char *mappath)
{
	if (!checkmap(map, mappath))
	{
		ft_printf("Error");
		return (0);
	}
	else if (!checkpande(map, mappath))
	{
		ft_printf("Error");
		return (0);
	}
	if (!checkc(map, mappath))
	{
		ft_printf("Error");
		return (0);
	}
	return (1);
}

// int	errorcheck2(char *mappath)
// {
// 	int	r;
// 	int	cc;

// 	r = getlinesize(mappath);
// 	cc = countlines(mappath);
// 	if (r <= cc)
// 	{
// 		ft_printf("Error");
// 		return (0);
// 	}
// 	return (1);
// }
