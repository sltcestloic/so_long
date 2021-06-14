/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:32:09 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/14 12:30:04 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_hooks(t_view view)
{
	mlx_hook(view.window, 2, 1L << 0, handle_key_press, &view);
	mlx_hook(view.window, 17, 1L << 17, handle_close_button, 0);
	mlx_loop_hook(view.mlx, render_frame, &view);
	mlx_loop(view.mlx);
}

void	init_window(t_view view)
{
	t_image		img;

	view.window = mlx_new_window(view.mlx, view.width, view.height,
			"so_long");
	view.image = &img;
	view.image->img = mlx_new_image(view.mlx, view.width,
			view.height);
	view.image->addr = mlx_get_data_addr(view.image->img,
			&view.image->bits_per_pixel,
			&view.image->line_len, &view.image->endian);
	init_hooks(view);
}
