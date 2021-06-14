/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:29:33 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/14 15:31:10 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_finished(t_view *view)
{
	static int	finished = 0;

	if (finished)
		exit(0);
	if (view->map->content[view->player->y][view->player->x] == 'E'
		&& count_collectibles(view->map) == 0)
		finished = 1;
}
