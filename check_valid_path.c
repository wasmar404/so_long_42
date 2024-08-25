/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 04:11:30 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 03:45:09 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_path_to_coin(char **tab, t_player size,
			t_player begin, t_count *p)
{
	check_valid_path_to_coin(tab, size, begin, p);
}

void	check_path_to_exit(char **tab, t_player size,
			t_player begin, t_count *p)
{
	check_valid_path_to_exit(tab, size, begin, p);
}
