/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_2d_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:33:52 by wasmar            #+#    #+#             */
/*   Updated: 2024/08/23 10:33:59 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*res;

	i = 0;
	while (src[i])
		i++;
	res = (char *)malloc(sizeof(*res) * i + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
	}
	if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

void	check_lines(char *line, char *temp, int fd)
{
	free(line);
	free(temp);
	close(fd);
	write(1, "ERROR\n", 6);
	exit(1);
}

char	*fill2darray(char *mappath)
{
	char	*line;
	char	*array;
	int		fd;
	char	*temp;

	fd = open(mappath, O_RDONLY);
	line = get_next_line(fd);
	temp = ft_strdup("");
	while (line)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)) != 0)
		{
			array = ft_strjoin(temp, line);
			free_two(line, temp);
			temp = ft_strdup(array);
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			free(array);
		}
		else
			check_lines(line, temp, fd);
	}
	free_and_close(temp, fd);
	return (array);
}

char	**array2d(char *mappath)
{
	char	*array;
	char	**splitedarray;

	array = fill2darray(mappath);
	splitedarray = ft_split(array, '\n');
	free(array);
	return (splitedarray);
}
