/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:57:40 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 03:45:27 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	freemem(char **map, char *mappath)
{
	int	i;

	i = 0;
	(void)mappath;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_two(char *str, char *str1)
{
	free(str);
	free(str1);
}

void	free_and_close(char *str, int fd)
{
	free(str);
	close(fd);
}
