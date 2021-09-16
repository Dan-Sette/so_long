/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:17:01 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/15 23:04:58 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_left_side(t_map *map, int line, int column)
{
	t_img	player;

	if ((column % 2 == 0 && line % 2 != 0)
		|| (column % 2 != 0 && line % 2 == 0))
		player.img = mlx_xpm_file_to_image(map->mlx_ptr,
				"./img/player_l_l.xpm", &player.img_width, &player.img_width);
	else
		player.img = mlx_xpm_file_to_image(map->mlx_ptr,
				"./img/player_l_r.xpm", &player.img_width, &player.img_width);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		player.img, column * 30, line * 30);
	mlx_destroy_image(map->mlx_ptr, player.img);
}

void	player_right_side(t_map *map, int line, int column)
{
	t_img	player;

	if ((column % 2 == 0 && line % 2 != 0)
		|| (column % 2 != 0 && line % 2 == 0))
		player.img = mlx_xpm_file_to_image(map->mlx_ptr,
				"./img/player_r_l.xpm", &player.img_width, &player.img_width);
	else
		player.img = mlx_xpm_file_to_image(map->mlx_ptr,
				"./img/player_r_r.xpm", &player.img_width, &player.img_width);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		player.img, column * 30, line * 30);
	mlx_destroy_image(map->mlx_ptr, player.img);
}

void	print_player(t_map *map)
{
	int		line;
	int		column;

	line = 0;
	while (map->lines[line] != NULL)
	{
		column = 0;
		while (map->lines[line][column] != '\0')
		{
			if (map->lines[line][column] == 'P')
			{
				if (map->side == 0)
					player_left_side(map, line, column);
				else
					player_right_side(map, line, column);
			}
			column++;
		}
		line++;
	}
}
