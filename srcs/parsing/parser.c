/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:05:30 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/24 14:40:45 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_empty(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 0)
		return (TRUE);
	while (line[i])
	{
		if (line[i] != ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	handle_empty_line(t_view *view, char *line)
{
	if (!view->map->parsed && view->map->content != NULL)
		view->map->parsed = TRUE;
	free(line);
}

int	read_line(t_view *view, char *line)
{
	if (view->map->parsed)
		return (print_error_exit("Invalid map.", 1));
	else if (parse_map_line(line, view) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	read_config(int fd, t_view *view)
{
	int		ret;
	char	*line;

	while (TRUE)
	{
		ret = ft_get_next_line(fd, &line);
		if (is_empty(line))
		{
			handle_empty_line(view, line);
			if (ret)
				continue ;
			break ;
		}
		if (read_line(view, line) == ERROR)
			return (ERROR);
		if (ret == 0)
			break ;
	}
	if (ret == -1)
		return (print_error_exit("Invalid .ber file.", 1));
	return (SUCCESS);
}

int	parse_config(int fd, t_map *map, t_view *view)
{
	view->map = map;
	view->enemy_count = 0;
	if (read_config(fd, view) == ERROR)
		return (ERROR);
	view->animation = 0;
	validate_map(map, view->player);
	close(fd);
	if (map->lines <= 28)
		view->height = map->lines * 50;
	else
		view->height = 1400;
	if (map->longest <= 40)
		view->width = map->longest * 50;
	else
		view->width = 2000;
	view->square_height = view->height / map->lines;
	view->square_width = view->width / map->longest;
	parse_textures(view);
	if (!view->has_exit)
		print_error_exit("No exit in map.", 1);
	return (SUCCESS);
}
