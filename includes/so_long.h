/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:21:40 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/10 13:39:25 by lbertran         ###   ########lyon.fr   */
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

typedef struct s_view
{
	void			*mlx;
	void			*window;
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

#endif