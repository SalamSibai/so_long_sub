/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:53:21 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/29 21:56:48 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	beginning_anim(t_so_long *sl)
{
	if (sl->start == 0)
	{
		if (sl->frame == 0)
		{
			if (sl->player->anim_loop > 0)
				sl->player->anim_loop --;
			else
				sl->start = 1;
		}
	}
}

void	blink_anim(t_so_long *sl)
{
	if (sl->start == 1)
	{
		if (sl->player->blink_frame == 0)
		{
			if (sl->player->blink_ctr <= 0)
			{
				sl->player->blink_frame = 10;
				sl->player->anim_loop = 1;
				sl->player->blink_ctr = 3;
			}
			else
			{
				sl->player->blink_frame = ANIM_FRAME;
				sl->player->blink_ctr --;
				sl->player->anim_loop = 0;
			}
		}
	}
}

void	set_player_anims(t_so_long *sl, int *len)
{
	sl->level->tiles->player[3] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/player/off.xpm", len, len);
	if (!sl->level->tiles->player[3])
		error_handler(NULL, sl, "no off player image\n", 1);
	sl->level->tiles->player[2] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/player/highlight.xpm", len, len);
	if (!sl->level->tiles->player[2])
		error_handler(NULL, sl, "no highlighted player image\n", 1);
	sl->level->tiles->player[1] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/player/blinking.xpm", len, len);
	if (!sl->level->tiles->player[1])
		error_handler(NULL, sl, "no blinking player image\n", 1);
	sl->level->tiles->player[0] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/player/idle.xpm", len, len);
	if (!sl->level->tiles->player[0])
		error_handler(NULL, sl, "no idle player image\n", 1);
}
