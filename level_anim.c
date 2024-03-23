/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:55:15 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/10 15:18:27 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_anim(t_so_long *sl)
{
	if (sl->level->enemy_num != 0)
	{
		if (sl->frame == 0)
			sl->enemy->open_frame = !sl->enemy->open_frame;
	}
}

void	decrement_frame_ctr(t_so_long *sl)
{
	if (sl->frame != 0)
		sl->frame --;
	else if (sl->frame <= 0)
		sl->frame = ANIM_FRAME;
	if (sl->player->blink_frame != 0)
		sl->player->blink_frame --;
	if (sl->level->enemy_num != 0)
	{
		if (sl->enemy->move_frame != 0)
			sl->enemy->move_frame--;
		else
			sl->enemy->move_frame = 10;
	}
}

void	flag_anim(t_so_long *sl)
{
	if (sl->frame == 0)
	{
		if (sl->level->reverse_flag == 0)
		{
			if (sl->level->flag_frame < 3)
			{
				sl->level->flag_frame++;
				if (sl->level->flag_frame == 3)
				{
					sl->level->reverse_flag = 1;
					sl->level->flag_frame -= 2;
				}
			}
		}
		else if (sl->level->reverse_flag == 1)
		{
			if (sl->level->flag_frame > 0)
			{
				sl->level->flag_frame--;
				if (sl->level->flag_frame == 0)
					sl->level->reverse_flag = 0;
			}
		}
	}
}
