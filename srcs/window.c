/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:32:09 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/10 13:39:07 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_hooks(t_view view)
{
	//mlx_hook(view.window, 4, 1L << 2, handle_click, &view);
	//mlx_hook(view.window, 5, 1L << 3, handle_click_release, &view);
	//mlx_hook(view.window, 2, 1L << 0, handle_key_press, &view);
	//mlx_hook(view.window, 3, 1L << 1, handle_key_release, &view);
	mlx_hook(view.window, 17, 1L << 17, handle_close_button, 0);
	//mlx_hook(view.window, 6, 1L << 6, handle_mouse_motion, &view);
	mlx_loop_hook(view.mlx, render_frame, &view);
	mlx_loop(view.mlx);
}

void	init_window(t_view view)
{
	view.window = mlx_new_window(view.mlx, 1280, 720,
			"so_long");
	init_hooks(view);
}
