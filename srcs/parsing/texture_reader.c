/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:43:21 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/14 12:29:46 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_texture(t_texture texture)
{
	if (texture.img == NULL)
		return (print_error("At least one texture is invalid in .cub file."));
	return (SUCCESS);
}

t_texture	read_texture(char *path, t_view *view)
{
	t_texture	texture;
	int			fd;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd == -1)
		print_error_exit("Invalid texture path in .cub file.", 1);
	texture.img = mlx_xpm_file_to_image(view->mlx, path, &texture.width,
			&texture.height);
	if (texture.img == NULL)
		print_error_exit("Invalid texture file in .cub file.", 1);
	texture.addr = (int *)mlx_get_data_addr(texture.img,
			&texture.bits_per_pixel, &texture.line_len, &texture.endian);
	return (texture);
}

void	parse_textures(t_view *view)
{
	view->wall_texture = read_texture("./.textures/wall.xpm", view);
	view->water_texture[0] = read_texture("./.textures/water0.xpm", view);
	view->water_texture[1] = read_texture("./.textures/water1.xpm", view);
	view->water_texture[2] = read_texture("./.textures/water2.xpm", view);
	view->water_texture[3] = read_texture("./.textures/water3.xpm", view);
	view->water_texture[4] = read_texture("./.textures/water4.xpm", view);
	view->player_texture = read_texture("./.textures/dolphin.xpm", view);
	view->fish_texture[0] = read_texture("./.textures/fish0.xpm", view);
	view->fish_texture[1] = read_texture("./.textures/fish1.xpm", view);
	view->fish_texture[2] = read_texture("./.textures/fish2.xpm", view);
	view->fish_texture[3] = read_texture("./.textures/fish3.xpm", view);
	view->fish_texture[4] = read_texture("./.textures/fish4.xpm", view);
	view->exit_texture = read_texture("./.textures/exit.xpm", view);
}
