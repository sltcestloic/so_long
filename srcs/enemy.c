/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:05:35 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/16 16:08:39 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enemies(t_view *view)
{
	int			i;
	static int	dead = 0;

	i = -1;
	if (dead)
	{
		printf("%sYou lost: you collided with an enemy patrol !%s\n",
			HRED, RESET);
		exit(0);
	}
	while (++i < view->enemy_count)
		if (view->enemy[i].x == view->player->x
			&& view->enemy[i].y == view->player->y)
			dead = 1;
}

void	move_enemy_x(t_view *view, t_enemy *enemy)
{
	if (enemy->movx != 0)
	{
		if (view->map->content[enemy->y][enemy->x + enemy->movx] == '1')
		{
			if (enemy->movx > 0)
				enemy->movx = -1;
			else
				enemy->movx = 1;
			move_enemy_x(view, enemy);
		}
		else
			enemy->x += enemy->movx;
	}
}

void	move_enemy(t_view *view, t_enemy *enemy)
{
	if (enemy->movy != 0)
	{
		if (view->map->content[enemy->y + enemy->movy][enemy->x] == '1')
		{
			if (enemy->movy > 0)
				enemy->movy = -1;
			else
				enemy->movy = 1;
			move_enemy(view, enemy);
		}
		else
			enemy->y += enemy->movy;
	}
	else
		move_enemy_x(view, enemy);
}

void	draw_enemies(t_view *view)
{
	int		i;

	i = -1;
	while (++i < view->enemy_count)
	{
		draw_texture(view, view->enemy[i].x * view->square_width,
			view->enemy[i].y * view->square_height,
			view->enemy_texture[view->animation / 10]);
	}
}

void	move_enemies(t_view *view)
{
	int	i;

	i = 0;
	while (i < view->enemy_count)
		move_enemy(view, &view->enemy[i++]);
}
