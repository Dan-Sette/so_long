/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:55:51 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/19 20:33:05 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_image
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_map {
	int		side;
	void	*win_ptr;
	void	*mlx_ptr;
	char	*lines[50];
	char	*backup[50];
	int		m_width;
	int		m_height;
	int		check_p;
	int		check_e;
	int		check_c;
	int		fd;
	int		steps;
}	t_map;

void	check_arguments(int argc, char **argv);
void	init_struct(t_map *map);
void	get_map_struct(char **argv, t_map *map);
void	count_map_pce(t_map *map);
void	map_handler(t_map *map);
void	move_up(t_map *map);
void	move_right(t_map *map);
void	move_bottom(t_map *map);
void	move_left(t_map *map);
void	print_map(t_map *map);
int		exit_map(t_map *map);
int		put_image(t_map *map);
void	print_grass(t_map *map);
void	print_barrel(t_map *map);
void	print_collectable(t_map *map);
void	print_player(t_map *map);
void	print_exit(t_map *map);
void	up(t_map *map, int line, int column);
void	right(t_map *map, int line, int column);
void	bottom(t_map *map, int line, int column);
void	left(t_map *map, int line, int column);
void	reset(t_map *map);

#endif
