/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:50:27 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/14 12:29:52 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_view *view, int x, int y, int color)
{
	char	*dst;

	if (x > view->width - 1 || x < 0 || y >= view->height - 1 || y < 0)
		return ;
	dst = view->image->addr + (y * view->image->line_len + x
			* (view->image->bits_per_pixel / 8));
	if ((color & 0x00FFFFFF) == 0)
		return ;
	*(unsigned int *)dst = color;
}

int	rgbint(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (65536 * r + 256 * g + b);
}

int	get_color(char c)
{
	if (c == '1')
		return (rgbint(0, 0, 0));
	else if (c == 'C')
		return (rgbint(102, 178, 255));
	else if (c == 'E')
		return (rgbint(0, 255, 0));
	else
		return (rgbint(255, 255, 255));
}
