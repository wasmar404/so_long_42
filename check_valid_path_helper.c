/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:13:00 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 03:45:05 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_valid_path_to_exit(char **tab, t_player size,
			t_player cur, t_count *p)
{
	if (!check_valid_char_exit(tab, cur.x, cur.y))
		return ;
	if (tab[cur.y][cur.x] == 'E')
		p->t_counte++;
	tab[cur.y][cur.x] = 'F';
	check_valid_path_to_exit(tab, size, (t_player){cur.x - 1, cur.y}, p);
	check_valid_path_to_exit(tab, size, (t_player){cur.x + 1, cur.y}, p);
	check_valid_path_to_exit(tab, size, (t_player){cur.x, cur.y - 1}, p);
	check_valid_path_to_exit(tab, size, (t_player){cur.x, cur.y + 1}, p);
}

int	check_valid_char_exit(char **map, int i, int j)
{
	if (map[j][i] == 'P' || map[j][i] == '0' || map[j][i] == 'C'
		|| map[j][i] == 'E')
		return (1);
	return (0);
}

int	check_valid_char_coin(char **map, int i, int j)
{
	if (map[j][i] == 'P' || map[j][i] == '0' || map[j][i] == 'C')
		return (1);
	return (0);
}

void	check_valid_path_to_coin(char **tab, t_player size,
			t_player cur, t_count *p)
{
	if (!check_valid_char_coin(tab, cur.x, cur.y))
		return ;
	if (tab[cur.y][cur.x] == 'C')
		p->t_countc++;
	tab[cur.y][cur.x] = 'F';
	check_valid_path_to_coin(tab, size, (t_player){cur.x - 1, cur.y}, p);
	check_valid_path_to_coin(tab, size, (t_player){cur.x + 1, cur.y}, p);
	check_valid_path_to_coin(tab, size, (t_player){cur.x, cur.y - 1}, p);
	check_valid_path_to_coin(tab, size, (t_player){cur.x, cur.y + 1}, p);
}
