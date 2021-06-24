/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:09:51 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/24 14:28:40 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_content(char **old, char **next, int mlc)
{
	size_t	i;

	i = 0;
	while (old[i])
	{
		next[i] = malloc(sizeof(char) * (mlc + 1));
		if (!next[i])
			print_error_exit("Error while allocating map copy.", 1);
		ft_bzero(next[i], mlc + 1);
		ft_strlcpy(next[i], old[i], ft_strlen(old[i]) + 1);
		i++;
	}
	next[i] = 0;
}

int	parse_map_line(char *line, t_view *view)
{
	char	**new_content;

	if (!validate_map_line(line, view))
	{
		print_error_exit("Invalid map line.", 1);
		return (ERROR);
	}
	new_content = malloc(sizeof(char *) * (view->map->lines + 2));
	if (!new_content)
	{
		if (view->map->content)
			free_split(view->map->content);
		return (ERROR);
	}
	if (view->map->longest < (int)ft_strlen(line))
		view->map->longest = ft_strlen(line);
	if (view->map->content)
	{
		copy_content(view->map->content, new_content, view->map->longest);
		free_split(view->map->content);
	}
	new_content[view->map->lines] = line;
	new_content[++view->map->lines] = 0;
	view->map->content = new_content;
	return (SUCCESS);
}
