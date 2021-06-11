/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:38:36 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/11 13:58:32 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close_button(void)
{
	exit(0);
	return (0);
}

int	handle_key_press(int keycode, t_view *view)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		view->player->y -= 1;
	else if (keycode == 0)
		view->player->x -= 1;
	else if (keycode == 1)
		view->player->y += 1;
	else if (keycode == 2)
		view->player->x += 1;
	return (0);
}

int	handle_key_release(int keycode, t_view *view)
{
	if (keycode == 13)
		view->keyboard->w_pressed = FALSE;
	else if (keycode == 0)
		view->keyboard->a_pressed = FALSE;
	else if (keycode == 1)
		view->keyboard->s_pressed = FALSE;
	else if (keycode == 2)
		view->keyboard->d_pressed = FALSE;
	return (0);
}
