/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:33:51 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/14 15:31:55 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_texture(t_view *view, int x, int y, t_texture texture)
{
	int		tx;
	int		ty;
	float	ratio_y;
	float	ratio_x;

	tx = 0;
	ty = 0;
	ratio_x = (float)texture.width / (float)view->square_width;
	ratio_y = (float)texture.height / (float)view->square_height;
	while (tx < view->square_width)
	{
		while (ty < view->square_height)
		{
			put_pixel(view, x + tx, y + ty, texture.addr[(int)
				((int)(ty * ratio_y) *texture.width + (int)(tx * ratio_x))]);
			ty++;
		}
		ty = 0;
		tx++;
	}
}

void	draw_square(t_view *view, int x, int y, char c)
{
	int	square_x;
	int	square_y;

	square_x = view->square_width;
	square_y = view->square_height;
	draw_texture(view, x * square_x, y * square_y,
		view->water_texture[view->animation / 10]);
	if (c == '1')
		draw_texture(view, x * square_x, y * square_y, view->wall_texture);
	else if (c == 'C')
		draw_texture(view, x * square_x, y * square_y,
			view->fish_texture[view->animation / 10]);
	else if (c == 'E')
		draw_texture(view, x * square_x, y * square_y,
			view->exit_texture[view->animation / 10]);
}

void	draw_map(t_view *view)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < view->map->lines)
	{
		while (j < view->map->longest)
		{
			draw_square(view, j, i, view->map->content[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_moves_background(t_view *view, int x, int y)
{
	int	cx;
	int	cy;
	int	oy;

	cx = x + 72;
	cy = y + 15;
	oy = y;
	while (x < cx)
	{
		while (y < cy)
		{
			put_pixel(view, x, y, rgbint(1, 1, 1));
			y++;
		}
		y = oy;
		x++;
	}
}

int	render_frame(t_view *view)
{
	char		*moves;
	char		*tmp;

	check_enemies(view);
	tmp = ft_itoa(view->move_count);
	moves = ft_strjoin("Moves: ", tmp);
	if (++view->animation > 49)
	{
		view->animation = 0;
		move_enemies(view);
	}
	free(tmp);
	draw_map(view);
	draw_texture(view, view->player->x * view->square_width,
		view->player->y * view->square_height,
		view->player_texture[view->animation / 10]);
	draw_enemies(view);
	draw_moves_background(view, 0, 0);
	mlx_put_image_to_window(view->mlx, view->window, view->image->img, 0, 0);
	mlx_string_put(view->mlx, view->window, 0, 10,
		rgbint(255, 255, 255), moves);
	free(moves);
	check_finished(view);
	return (0);
}
