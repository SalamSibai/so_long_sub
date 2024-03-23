/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:37:29 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/29 17:50:18 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_so_long *sl)
{
	cleanup(sl);
	exit(0);
}

int	close_window(t_so_long	*sl)
{
	mlx_clear_window(sl->data->mlx_ptr, sl->data->win);
	mlx_destroy_window(sl->data->mlx_ptr, sl->data->win);
	exit_game(sl);
	return (0);
}

void	print_moves_to_window(t_so_long *sl)
{
	char	*moves_num;

	moves_num = ft_itoa(sl->player->moves_no);
	mlx_string_put(sl->data->mlx_ptr, sl->data->win, 20, 10, 0x0000FF00,
		"Number of moves: ");
	mlx_string_put(sl->data->mlx_ptr, sl->data->win, 140, 10, 0x0000FF00,
		moves_num);
	mlx_string_put(sl->data->mlx_ptr,
		sl->data->win, (sl->level->columns * 64) - 150, 10, 0x00FF0000,
		"Inspired by: TABADAWI");
}
