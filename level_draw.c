/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:56:42 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/29 16:57:24 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_mlx_data *mlx, void *img, int col, int row)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img,
		col * 64, row * 64);
}

void	draw_flag(t_so_long *sl, int frame)
{
	put_img(sl->data, sl->level->tiles->exit[frame],
		sl->level->exit_x, sl->level->exit_y);
}

void	draw_enemy(t_so_long *sl, int frame, int num)
{
	int	i;

	i = 0;
	if (sl->level->enemy_num != 0)
	{
		if (num == -1)
		{
			while (i < sl->level->enemy_num)
			{
				put_img(sl->data, sl->level->tiles->enemy[frame],
					sl->enemy->x_pos[i], sl->enemy->y_pos[i]);
				i++;
			}
		}
		else
		{
			put_img(sl->data, sl->level->tiles->enemy[frame],
				sl->enemy->x_pos[0], sl->enemy->y_pos[0]);
		}
	}
}

/// @brief draws the player at a specific frame
/// @param sl the sl pointer
/// @param pos_x the x position of the player
/// @param pos_y the y position of the player
/// @param frame the frame
///					0 is off
///					1 is highlighted
///					2 is blinking
///					4 is idle
void	draw_player(t_so_long *sl, int frame)
{
	put_img(sl->data, sl->level->tiles->player[frame],
		sl->player->x_pos, sl->player->y_pos);
}

void	print_moves(t_so_long *sl)
{
	if (sl->printed == 0 && sl->player->moved == 1)
	{
		sl->player->moves_no ++;
		ft_printf("moves number : %d\n", sl->player->moves_no);
		sl->printed = 1;
	}
}
