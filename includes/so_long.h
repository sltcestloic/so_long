/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:21:40 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/11 13:38:16 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# ifndef ERROR
#   define ERROR -1
# endif
# ifndef SUCCESS
#   define SUCCESS 1
# endif
# define WIDTH 1280
# define HEIGHT 720

typedef struct s_keyboard
{
	int				w_pressed;
	int				a_pressed;
	int				s_pressed;
	int				d_pressed;
}					t_keyboard;

typedef struct s_player
{
	float			x;
	float			y;
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

typedef struct s_view
{
	void			*mlx;
	void			*window;
	int				move_count;
	t_keyboard		*keyboard;
	t_player		*player;
	t_map			*map;
	t_image			*image;
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

#endif