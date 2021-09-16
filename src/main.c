/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:52:54 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/15 23:29:16 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("ERROR\nInvalid number of argument\n", 1);
		exit (0);
	}
	if (!ft_strrchr(argv[1], '.') || ft_strlen(argv[1]) < 4)
	{
		ft_putstr_fd("ERROR\nInvalid argument\n", 1);
		exit (0);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), (const char *)".ber", 4) != 0)
	{
		ft_putstr_fd("ERROR\nThe argument must be of type \".ber\"\n", 1);
		exit (0);
	}
}

void	init_struct(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
}

int	main(int argc, char **argv)
{
	t_map	map;

	check_arguments(argc, argv);
	init_struct(&map);
	get_map_struct(argv, &map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.m_width * 30,
			map.m_height * 30, "GAME");
	map_handler(&map);
	close(map.fd);
	exit_map(&map);
	return (0);
}
