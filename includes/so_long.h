/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:21:40 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/24 14:34:14 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# ifndef ERROR
#  define ERROR -1
# endif
# ifndef SUCCESS
#  define SUCCESS 1
# endif

typedef struct s_player
{
	int				x;
	int				y;
}					t_player;

typedef struct s_map
{
	char			**content;
	char			**content_copy;
	int				lines;
	int				longest;
	int				parsed;
}					t_map;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}					t_image;

typedef struct s_texture
{
	void			*img;
	int				width;
	int				height;
	int				*addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}					t_texture;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				movx;
	int				movy;
}					t_enemy;

typedef struct s_view
{
	void			*mlx;
	void			*window;
	int				move_count;
	int				height;
	int				width;
	int				animation;
	int				square_height;
	int				square_width;
	t_player		*player;
	t_map			*map;
	t_image			*image;
	t_texture		wall_texture;
	t_texture		water_texture[5];
	t_texture		player_texture[5];
	t_texture		fish_texture[5];
	t_texture		enemy_texture[5];
	t_texture		exit_texture[5];
	t_enemy			enemy[50];
	int				enemy_count;
}					t_view;

/*
** Errors
*/

int					print_error(char *message);
int					print_error_exit(char *message, int ext);

/*
** Window
*/

void				init_window(t_view view);

/*
** Render
*/

int					render_frame(t_view *view);
void				draw_texture(t_view *view, int x, int y, t_texture texture);
void				draw_enemies(t_view *view);

/*
** Hooks handlers
*/

int					handle_close_button(void);
int					handle_key_press(int keycode, t_view *view);
int					handle_key_release(int keycode, t_view *view);

/*
** Parsing
*/

int					parse_config(int fd, t_map *map, t_view *view);
int					parse_map_line(char *line, t_view *view);
void				copy_content(char **old, char **next, int mlc);

/*
** Validation
*/

int					validate_map_line(char *line, t_view *view);
int					is_valid_map_char(char c);
int					validate_map(t_map *map, t_player *player);

/*
** Map
*/

int					count_collectibles(t_map *map);

/*
** Textures
*/

t_texture			read_texture(char *path, t_view *view);
void				parse_textures(t_view *view);

/*
** Color
*/

void				put_pixel(t_view *view, int x, int y, int color);
int					rgbint(int r, int g, int b);
int					get_color(char c);

/*
** Enemies
*/

void				move_enemies(t_view *view);
void				check_enemies(t_view *view);

/*
** ?
*/

void				check_finished(t_view *view);

#endif