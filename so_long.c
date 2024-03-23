/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:08:28 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/29 21:12:06 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int key, t_so_long *sl)
{
	if (key == ESC)
		close_window(sl);
	else
	{
		if (sl->player->pressed == 0 && sl->start == 1)
		{
			if ((key == UP || key == W)
				|| (key == DOWN || key == S)
				|| (key == RIGHT || key == D)
				|| (key == LEFT || key == A))
			{
				sl->player->moved = 0;
				sl->player->pressed = 1;
				sl->player->move_dr = key;
				player_movement(sl);
			}
		}
	}
	return (0);
}

int	handle_keyrelease(int key, t_so_long *sl)
{
	if ((key == UP || key == W)
		|| (key == DOWN || key == S)
		|| (key == RIGHT || key == D)
		|| (key == LEFT || key == A))
		sl->printed = 0;
	return (0);
}

int	update(t_so_long *sl)
{
	decrement_frame_ctr(sl);
	beginning_anim(sl);
	blink_anim(sl);
	enemy_anim(sl);
	flag_anim(sl);
	move_enemies(sl);
	if (sl->player->pressed)
	{
		player_movement(sl);
		mlx_clear_window(sl->data->mlx_ptr, sl->data->win);
		draw_map(sl, 0, 0);
	}
	if (sl->level->enemy_num > 1)
		draw_enemy(sl, sl->enemy->open_frame, -1);
	else if (sl->level->enemy_num == 1)
		draw_enemy(sl, sl->enemy->open_frame, 0);
	draw_flag(sl, sl->level->flag_frame);
	draw_player(sl, sl->player->anim_loop);
	check_pos(sl);
	print_moves_to_window(sl);
	return (0);
}

/// @brief main game loop
/// @param sl the so long struct
/*
	mlx_hook: handles keypresses on any button on the keyboard
*/
void	so_long(t_so_long *sl)
{
	sl->data->mlx_ptr = mlx_init();
	sl->data->win = mlx_new_window(sl->data->mlx_ptr, sl->level->columns * 64,
			sl->level->rows * 64, "so_long");
	make_map(sl);
	if (!sl->data->win)
		ft_putstr_fd ("Error: failed to open window\n", 2);
	mlx_hook(sl->data->win, 2, 0, &handle_keypress, sl);
	mlx_hook(sl->data->win, 17, 0, &close_window, sl);
	mlx_key_hook(sl->data->win, &handle_keyrelease, sl);
	mlx_loop_hook(sl->data->mlx_ptr, &update, sl);
	mlx_loop(sl->data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_so_long	*sl;

	if (ac != 2)
		return (0);
	sl = malloc(sizeof (t_so_long));
	if (!sl)
		error_handler(NULL, NULL, "No space for so_long struct\n", 0);
	initialize(sl);
	validate_level(av[1], sl);
	if (sl->level->enemy_num != 0)
		init_enemy(sl);
	if (!sl->level)
		return (0);
	so_long(sl);
	return (0);
}
