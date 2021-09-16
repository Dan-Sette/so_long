/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:02:12 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/15 23:30:10 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int key_code, t_map *map)
{
	if (key_code == 0xff52 || key_code == 'w')
		move_up(map);
	else if (key_code == 0xff53 || key_code == 'd')
	{
		map->side = 1;
		move_right(map);
	}
	else if (key_code == 0xff54 || key_code == 's')
		move_bottom(map);
	else if (key_code == 0xff51 || key_code == 'a')
	{
		map->side = 0;
		move_left(map);
	}
	else if (key_code == 0xff1b)
		exit_map(map);
	else if (key_code == 0x0072)
		reset(map);
	printf("\nSteps: %i\n", map->steps);
	printf("\n");
	put_image(map);
	return (0);
}

int	exit_map(t_map *map)
{
	int		line;

	line = map->m_height;
	while (line >= 0)
	{
		free(map->lines[line]);
		free(map->backup[line]);
		line--;
	}
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	exit (0);
	return (0);
}

void	reset(t_map *map)
{
	int	line;

	map->m_height = 0;
	map->side = 0;
	map->steps = 0;
	map->check_C = 0;
	line = 0;
	while (map->backup[line] != NULL)
	{
		free(map->lines[line]);
		line++;
	}
	line = 0;
	while (map->backup[line] != NULL)
	{
		map->lines[line] = ft_strdup(map->backup[line]);
		line++;
		map->m_height++;
	}
	count_map_PCE(map);
	map->m_width = ft_strlen(&map->lines[0][0]);
	map->lines[map->m_height + 1] = NULL;
	map_handler(map);
}

void	map_handler(t_map *map)
{
	mlx_expose_hook(map->win_ptr, put_image, map);
	put_image(map);
	mlx_hook(map->win_ptr, 2, 1L << 0, move_player, map);
	mlx_hook(map->win_ptr, 33, 1L << 5, exit_map, map);
	mlx_loop(map->mlx_ptr);
}
