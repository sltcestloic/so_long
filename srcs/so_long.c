/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:22:47 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/24 14:39:33 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_args(int ac, char **av, int *fd)
{
	if (ac != 2)
	{
		print_error_exit("Usage: ./so_long <map path>", 1);
		return (FALSE);
	}
	*fd = open(av[1], O_RDONLY);
	if (ft_strcmp(".ber", &(av[1])[ft_strlen(av[1]) - 4]) != 0)
		print_error_exit("File is not a .ber file.", 1);
	if (*fd == -1)
	{
		print_error_exit("Please provide a valid file path.", 1);
		return (FALSE);
	}
	return (TRUE);
}

static void	init_map(t_map *map)
{
	map->content = NULL;
	map->lines = 0;
	map->longest = 0;
	map->parsed = FALSE;
}

void	init_player(t_player *player)
{
	player->x = -1;
	player->y = -1;
}

int	main(int ac, char **av)
{
	int			fd;
	t_view		view;
	t_player	player;
	t_map		map;

	validate_args(ac, av, &fd);
	view.mlx = mlx_init();
	view.move_count = 0;
	view.has_exit = 0;
	init_player(&player);
	view.player = &player;
	init_map(&map);
	if (parse_config(fd, &map, &view))
		init_window(view);
}
