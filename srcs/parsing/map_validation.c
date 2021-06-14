/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:10:04 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/14 12:35:49 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_map_validation(t_map *map, int x, int y)
{
	if (map->content_copy[y][x] != '1')
	{
		if (x == 0 || y == 0 || x == map->longest - 1 || y == map->lines - 1)
		{
			print_error_exit("Invalid map. (Check #1)", 1);
		}
		if (map->content_copy[y][x] == ' ')
			print_error_exit("Invalid map. (Check #2)", 1);
		map->content_copy[y][x] = '1';
		run_map_validation(map, x + 1, y);
		run_map_validation(map, x + 1, y + 1);
		run_map_validation(map, x + 1, y - 1);
		run_map_validation(map, x, y + 1);
		run_map_validation(map, x, y - 1);
		run_map_validation(map, x - 1, y);
		run_map_validation(map, x - 1, y + 1);
		run_map_validation(map, x - 1, y - 1);
	}
}

void	check_player(int x, int y, t_player *player)
{
	if (player->x == -1)
	{
		player->x = x;
		player->y = y;
	}
	else
		print_error_exit("More than one player in map.", 1);
}

int	validate_map_line(char *line, t_view *view)
{
	size_t	i;

	i = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	if (!line[i] || line[i] != '1')
		return (FALSE);
	while (line[i])
	{
		if (line[i] == 'P')
			check_player(i, view->map->lines, view->player);
		if (!is_valid_map_char(line[i]))
			print_error_exit("Invalid character in map.", 1);
		i++;
	}
	if (line[i - 1] != '1')
		return (FALSE);
	return (TRUE);
}

int	validate_map(t_map *map, t_player *player)
{
	if (!map->content)
		return (print_error_exit("No map in .ber file.", 1));
	map->content_copy = malloc(sizeof(char *) * (map->lines + 2));
	if (!map->content_copy)
		return (print_error_exit("Map copy malloc failed.", 1));
	copy_content(map->content, map->content_copy, map->longest);
	if (player->x < 0)
		print_error_exit("No player in map.", 1);
	map->content_copy[(int)player->y][(int)player->x] = '0';
	run_map_validation(map, (int)player->x, (int)player->y);
	if (count_collectibles(map) == 0)
		return (FALSE);
	return (TRUE);
}
