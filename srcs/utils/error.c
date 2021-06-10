/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:27:54 by lbertran          #+#    #+#             */
/*   Updated: 2021/06/10 13:36:02 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error_exit(char *message, int ext)
{
	printf("Error\n");
	printf(HRED);
	printf("%s\n", message);
	printf(RESET);
	if (ext)
		exit(0);
	return (ERROR);
}

int	print_error(char *message)
{
	return (print_error_exit(message, 0));
}
