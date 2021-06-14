/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:38:36 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/14 15:24:25 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close_button(void)
{
	exit(0);
	return (0);
}

void	handle_movement(t_view *view, int x, int y)
{
	char	c;

	c = view->map->content[y][x];
	if (c == '1')
		return ;
	view->move_count++;
	view->player->x = x;
	view->player->y = y;
	if (c == 'C')
		view->map->content[y][x] = '0';
}

int	handle_key_press(int keycode, t_view *view)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		handle_movement(view, view->player->x, view->player->y - 1);
	else if (keycode == 0)
		handle_movement(view, view->player->x - 1, view->player->y);
	else if (keycode == 1)
		handle_movement(view, view->player->x, view->player->y + 1);
	else if (keycode == 2)
		handle_movement(view, view->player->x + 1, view->player->y);
	return (0);
}
