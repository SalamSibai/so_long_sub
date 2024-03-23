/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:58:49 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/29 16:59:02 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_monster_draw(t_so_long *sl, int row, int column, int *ctr)
{
	if (++(*ctr) < sl->level->enemy_num)
	{
		sl->enemy->x_pos[*ctr] = column;
		sl->enemy->y_pos[*ctr] = row;
		draw_enemy(sl, 0, *ctr);
	}
}

void	initial_exit_draw(t_so_long *sl, int row, int column)
{
	sl->level->exit_x = column;
	sl->level->exit_y = row;
	draw_flag(sl, 0);
}

void	initial_player_draw(t_so_long *sl, int row, int column)
{
	sl->player->x_pos = column;
	sl->player->y_pos = row;
	draw_player(sl, 0);
}
