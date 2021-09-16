/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:12:33 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/15 23:05:03 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_image(t_map *map)
{
	print_grass(map);
	print_barrel(map);
	print_collectable(map);
	print_player(map);
	print_exit(map);
	return (0);
}

void	print_barrel(t_map *map)
{
	t_img	barrel;
	int		line;
	int		column;

	barrel.img = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/barrel.xpm", &barrel.img_width,
			&barrel.img_height);
	line = 0;
	while (map->lines[line] != NULL)
	{
		column = 0;
		while (map->lines[line][column] != '\0')
		{
			if (map->lines[line][column] == '1')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					barrel.img, column * 30, line * 30);
			}
			column++;
		}
		line++;
	}
	mlx_destroy_image(map->mlx_ptr, barrel.img);
}

void	print_grass(t_map *map)
{
	t_img	grass;
	int		line;
	int		column;

	grass.img = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/grass.xpm", &grass.img_width,
			&grass.img_width);
	line = 0;
	while (map->lines[line] != NULL)
	{
		column = 0;
		while (map->lines[line][column] != '\0')
		{
			if (map->lines[line][column] == '0')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					grass.img, column * 30, line * 30);
			}
			column++;
		}
		line++;
	}
	mlx_destroy_image(map->mlx_ptr, grass.img);
}

void	print_collectable(t_map *map)
{
	t_img	collectable;
	int		line;
	int		column;

	collectable.img = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/collectable.xpm", &collectable.img_width,
			&collectable.img_width);
	line = 0;
	while (map->lines[line] != NULL)
	{
		column = 0;
		while (map->lines[line][column] != '\0')
		{
			if (map->lines[line][column] == 'C')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					collectable.img, column * 30, line * 30);
			}
			column++;
		}
		line++;
	}
	mlx_destroy_image(map->mlx_ptr, collectable.img);
}

void	print_exit(t_map *map)
{
	t_img	exit;
	int		line;
	int		column;

	exit.img = mlx_xpm_file_to_image(map->mlx_ptr,
			"./img/exit.xpm", &exit.img_width,
			&exit.img_width);
	line = 0;
	while (map->lines[line] != NULL)
	{
		column = 0;
		while (map->lines[line][column] != '\0')
		{
			if (map->lines[line][column] == 'E')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					exit.img, column * 30, line * 30);
			}
			column++;
		}
		line++;
	}
	mlx_destroy_image(map->mlx_ptr, exit.img);
}
