/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:22:47 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/10 13:37:55 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_args(int ac, char **av, int *fd)
{
	if (ac != 2)
	{
		print_error_exit("Usage: ./so_long <map path>", 1);
		return (FALSE);
	}
	*fd = open(av[1], O_RDONLY);
	if (ft_strcmp(".ber", &(av[1])[ft_strlen(av[1]) - 4]) != 0)
		print_error_exit("File is not a .ber file.", 1);
	if (*fd == -1)
	{
		print_error_exit("Please provide a valid file path.", 1);
		return (FALSE);
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	int		fd;
	t_view	view;

	validate_args(ac, av, &fd);
	view.mlx = mlx_init();
	init_window(view);
}