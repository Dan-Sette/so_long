/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:55:50 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/15 23:04:53 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	int		line;
	int		column;

	map->steps += 1;
	line = 0;
	while (map->lines[line] != NULL)
	{
		column = 0;
		while (map->lines[line][column] != '\0')
		{
			up(map, line, column);
			column++;
		}
		line++;
	}	
}

void	move_right(t_map *map)
{
	int		line;
	int		column;

	map->steps += 1;
	line = 0;
	while (map->lines[line] != NULL)
	{
		column = ft_strlen(map->lines[line]);
		while (column >= 0)
		{	
			right(map, line, column);
			column--;
		}
		line++;
	}
}

void	move_bottom(t_map *map)
{
	int		line;
	int		column;

	map->steps += 1;
	line = map->m_height - 1;
	while (line >= 0)
	{
		column = 0;
		while (map->lines[line][column] != '\0')
		{
			bottom(map, line, column);
			column++;
		}
		line--;
	}
}

void	move_left(t_map *map)
{
	int		line;
	int		column;

	map->steps += 1;
	line = 0;
	while (map->lines[line] != NULL)
	{
		column = 0;
		while (map->lines[line][column] != '\0')
		{
			left(map, line, column);
			column++;
		}
		line++;
	}
}
