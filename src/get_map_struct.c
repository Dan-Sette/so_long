/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:03:28 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/15 23:04:22 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 
#include "get_next_line.h"
#include <string.h>

void	check_map_wall(t_map *map)
{
	int	i;

	i = 0;
	while (map->lines[0][i] != '\0' && map->lines[map->m_height - 1][i] != '\0')
	{
		if (map->lines[0][i] != '1' || map->lines[map->m_height - 1][i] != '1')
		{
			ft_putstr_fd("ERROR\nMap must be surrounded by wall\n", 1);
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i < map->m_height)
	{
		if (map->lines[i][0] != '1' || map->lines[i][map->m_width - 1] != '1')
		{
			ft_putstr_fd("ERROR\nMap must be surrounded by wall\n", 1);
			exit (1);
		}
		i++;
	}
}

void	count_map_PCE(t_map *map)
{
	size_t	j;
	size_t	i;

	j = 0;
	while (map->lines[j] != NULL)
	{
		i = 0;
		while (map->lines[j][i] != '\0')
		{
			if (map->lines[j][i] == 'P')
				map->check_P++;
			if (map->lines[j][i] == 'C')
				map->check_C++;
			if (map->lines[j][i] == 'E')
				map->check_E++;
			i++;
		}
		j++;
	}
}

void	check_error_PCE(t_map *map)
{
	if (map->check_P != 1 || map->check_E != 1 || map->check_C < 1)
	{
		if (map->check_P != 1)
			ft_putstr_fd("ERROR\nMap must include 1 player (only 1)\n", 1);
		if (map->check_E != 1)
			ft_putstr_fd("ERROR\nMap must include 1 exit point (only 1)\n", 1);
		if (map->check_C < 1)
			ft_putstr_fd("ERROR\nMap must include at least 1 collectable", 1);
		exit (0);
	}
}

void	check_map_content(char *line)
{
	int	column;

	column = 0;
	while (line[column])
	{
		if (line[column] != 'P' && line[column] != 'C'
			&& line[column] != '1' && line[column] != '0'
			&& line[column] != 'E')
		{
			ft_putstr_fd("ERROR\nIs there any wrong character on the map", 1);
			exit (1);
		}
		column++;
	}
}

void	get_map_struct(char **argv, t_map *map)
{
	const char	*address;
	int			line;
	size_t		gnl_output;

	address = argv[1];
	line = 0;
	map->fd = open(address, O_RDONLY);
	gnl_output = 1;
	while (gnl_output != 0)
	{
		gnl_output = get_next_line(map->fd, &map->lines[line]);
		map->backup[line] = ft_strdup(map->lines[line]);
		check_map_content(map->lines[line]);
		map->m_height++;
		line++;
	}
	map->m_width = ft_strlen(&map->lines[0][0]);
	map->lines[map->m_height + 1] = NULL;
	check_map_wall(map);
	count_map_PCE(map);
	check_error_PCE(map);
}
