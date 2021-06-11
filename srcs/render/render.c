/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:33:51 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/11 13:57:10 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_view *view, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH - 1 || x < 0 || y >= HEIGHT - 1 || y < 0)
		return ;
	dst = view->image->addr + (y * view->image->line_len + x
			* (view->image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	rgbint(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (65536 * r + 256 * g + b);
}

int	draw_square(t_view *view, int x, int y, int color)
{
	int	rx = WIDTH / view->map->longest;
	int	ry = HEIGHT / view->map->lines;
	int	cx = rx * x;
	int cy = ry * y;
	while (cy < ry * (y + 1))
	{
		while (cx < rx * (x + 1))
		{
			put_pixel(view, cx, cy, color);
			//mlx_pixel_put(view->mlx, view->window, cx, cy, color);
			cx++;
		}
		cx = rx * x;
		cy++;
	}
	return 1;
}

int	render_frame(t_view *view)
{
	int color;
	for (int i = 0; i < view->map->lines; i++)
	{
		for (int j = 0; view->map->content[i][j]; j++)
		{
			if (view->map->content[i][j] == '1')
				color = rgbint(0, 0, 0);
			else color = rgbint(255, 255, 255);
			draw_square(view, j, i, color);
		}
	}
	draw_square(view, view->player->x, view->player->y, rgbint(255, 0, 0));
	mlx_put_image_to_window(view->mlx, view->window, view->image->img, 0, 0);
	return (0);
}
