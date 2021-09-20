/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sides_up_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:00:22 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/19 20:57:42 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_map *map, int line, int column)
{
	if (map->lines[line][column] == 'P' &&
		map->lines[line - 1][column] != '1' &&
		map->lines[line - 1][column] != 'E')
	{
		if (map->lines[line - 1][column] == 'C')
			map->check_c -= 1;
		map->lines[line][column] = '0';
		map->lines[line - 1][column] = 'P';
		map->steps += 1;
	}
	if (map->lines[line][column] == 'P' &&
		map->lines[line - 1][column] == 'E' &&
		map->check_c == 0)
	{
		map->lines[line][column] = '0';
		map->lines[line - 1][column] = 'P';
		map->steps += 1;
		exit_map(map);
	}
}

void	right(t_map *map, int line, int column)
{
	if (map->lines[line][column] == 'P' &&
		map->lines[line][column + 1] != '1' &&
		map->lines[line][column + 1] != 'E')
	{
		if (map->lines[line][column + 1] == 'C')
			map->check_c -= 1;
		map->lines[line][column] = '0';
		map->lines[line][column + 1] = 'P';
		map->steps += 1;
	}
	if (map->lines[line][column] == 'P' &&
			map->lines[line][column + 1] == 'E' &&
			map->check_c == 0)
	{
		map->lines[line][column] = '0';
		map->lines[line][column + 1] = 'P';
		map->steps += 1;
		exit_map(map);
	}
}

void	bottom(t_map *map, int line, int column)
{
	if (map->lines[line][column] == 'P' &&
		map->lines[line + 1][column] != '1' &&
		map->lines[line + 1][column] != 'E')
	{
		if (map->lines[line + 1][column] == 'C')
			map->check_c -= 1;
		map->lines[line][column] = '0';
		map->lines[line + 1][column] = 'P';
		map->steps += 1;
	}
	if (map->lines[line][column] == 'P' &&
		map->lines[line + 1][column] == 'E' &&
		map->check_c == 0)
	{
		map->lines[line][column] = '0';
		map->lines[line + 1][column] = 'P';
		map->steps += 1;
		exit_map(map);
	}
}

void	left(t_map *map, int line, int column)
{
	if (map->lines[line][column] == 'P' &&
		map->lines[line][column - 1] != '1' &&
		map->lines[line][column - 1] != 'E')
	{
		if (map->lines[line][column - 1] == 'C')
			map->check_c -= 1;
		map->lines[line][column] = '0';
		map->lines[line][column - 1] = 'P';
		map->steps += 1;
	}
	if (map->lines[line][column] == 'P' &&
		map->lines[line][column - 1] == 'E' &&
		map->check_c == 0)
	{
		map->lines[line][column] = '0';
		map->lines[line][column - 1] = 'P';
		map->steps += 1;
		exit_map(map);
	}
}
