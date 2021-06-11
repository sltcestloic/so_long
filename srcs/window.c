/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:32:09 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/11 13:47:27 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_hooks(t_view view)
{
	//mlx_hook(view.window, 4, 1L << 2, handle_click, &view);
	//mlx_hook(view.window, 5, 1L << 3, handle_click_release, &view);
	mlx_hook(view.window, 2, 1L << 0, handle_key_press, &view);
	//mlx_hook(view.window, 3, 1L << 1, handle_key_release, &view);
	mlx_hook(view.window, 17, 1L << 17, handle_close_button, 0);
	//mlx_hook(view.window, 6, 1L << 6, handle_mouse_motion, &view);
	mlx_loop_hook(view.mlx, render_frame, &view);
	mlx_loop(view.mlx);
}

void	init_keyboard(t_keyboard *keyboard)
{
	keyboard->w_pressed = FALSE;
	keyboard->a_pressed = FALSE;
	keyboard->s_pressed = FALSE;
	keyboard->d_pressed = FALSE;
}


void	init_window(t_view view)
{
	t_keyboard	keyboard;
	t_image		img;

	view.window = mlx_new_window(view.mlx, WIDTH, HEIGHT,
			"so_long");
	init_keyboard(&keyboard);
	view.keyboard = &keyboard;
	view.image = &img;
	view.image->img = mlx_new_image(view.mlx, WIDTH,
			HEIGHT);
	view.image->addr = mlx_get_data_addr(view.image->img,
			&view.image->bits_per_pixel,
			&view.image->line_len, &view.image->endian);
	init_hooks(view);
}
