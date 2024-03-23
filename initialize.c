/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:07:55 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/03 22:53:34 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_so_long *sl)
{
	int	i;

	i = -1;
	sl->enemy = malloc(sizeof(t_enemy));
	if (!sl->enemy)
		error_handler(NULL, sl, "Error: no space for enemy struct\n", 1);
	sl->enemy->x_pos = malloc(sl->level->enemy_num * sizeof(int));
	if (!sl->enemy->x_pos)
		error_handler(NULL, sl, "Error: no space for enemy struct\n", 1);
	sl->enemy->y_pos = malloc(sl->level->enemy_num * sizeof(int));
	if (!sl->enemy->y_pos)
		error_handler(NULL, sl, "Error: no space for enemy struct\n", 1);
	sl->enemy->open_frame = 0;
	sl->enemy->x_axis_mov = malloc(sl->level->enemy_num * sizeof(int));
	if (!sl->enemy->x_axis_mov)
		error_handler(NULL, sl, "Error: no space for enemy mov axis\n", 1);
	sl->enemy->dir = malloc(sl->level->enemy_num * sizeof(int));
	if (!sl->enemy->dir)
		error_handler(NULL, sl, "Error: no space for direction\n", 1);
	while (++i < sl->level->enemy_num)
	{
		sl->enemy->dir[i] = i % 2;
		sl->enemy->x_axis_mov[i] = i % 2;
	}
	sl->enemy->move_frame = 10;
}

void	init_player(t_player *player)
{
	player->move_dr = -1;
	player->moves_no = 0;
	player->pressed = 0;
	player->x_pos = 0;
	player->y_pos = 0;
	player->collected = 0;
	player->moved = 0;
}

void	initialize(t_so_long *sl)
{
	sl->frame = ANIM_FRAME;
	sl->start = 0;
	sl->printed = 0;
	sl->data = malloc(sizeof(t_mlx_data));
	if (!(sl->data))
		error_handler(NULL, sl, "Error: no space for mlx_data struct\n", 1);
	sl->player = malloc(sizeof(t_player));
	if (!(sl->player))
		error_handler(NULL, sl, "Error: no space for player struct\n", 1);
	sl->level = malloc(sizeof(t_level));
	if (!sl->level)
		error_handler(NULL, sl, "Error: No space for level struct\n", 1);
	if (init_level(sl->level) == 0)
		error_handler(NULL, sl, "Error: No space for tiles\n", 1);
	sl->player->anim_loop = 3;
	sl->player->blink_ctr = 2;
	sl->player->blink_frame = ANIM_FRAME;
	sl->enemy = NULL;
	sl->data->mlx_ptr = NULL;
	sl->data->win = NULL;
	init_player(sl->player);
}
