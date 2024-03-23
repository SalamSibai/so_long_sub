/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:52:21 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/04 20:08:34 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_enemy_tiles(t_so_long *sl, int *len)
{
	sl->level->tiles->enemy[0] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/enemy/enemy0.xpm", len, len);
	if (!sl->level->tiles->enemy[0])
		error_handler(NULL, sl, "no enemy image.\n", 1);
	sl->level->tiles->enemy[1] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/enemy/enemy1.xpm", len, len);
	if (!sl->level->tiles->enemy[1])
		error_handler(NULL, sl, "no enemy image.\n", 1);
}

static int	safe_tile(int new_x, int new_y, t_so_long *sl)
{
	if ((new_y > 0 && new_y < (sl->level->rows - 1))
		&& (new_x > 0 && new_x < (sl->level->columns - 1))
		&& (sl->level->map[new_y][new_x] != '1')
		&& (sl->level->map[new_y][new_x] != 'E')
		&& (sl->level->map[new_y][new_x] != 'C'))
	{
		if (sl->level->map[new_y][new_x] == 'P')
		{
			if (sl->player->pressed)
				print_moves(sl);
			ft_printf("!!YOU DIED!!\n");
			close_window(sl);
		}
		else
			return (1);
	}
	return (0);
}

static void	move_x(t_so_long *sl, int num)
{
	int	old_x;
	int	old_y;

	old_x = sl->enemy->x_pos[num];
	old_y = sl->enemy->y_pos[num];
	if (sl->enemy->dir[num] == 0)
	{
		if (safe_tile(old_x + 1, old_y, sl))
		{
			sl->level->map[old_y][old_x] = '0';
			sl->enemy->x_pos[num]++;
		}
		else
			sl->enemy->dir[num] = !sl->enemy->dir[num];
	}
	if (sl->enemy->dir[num] == 1)
	{
		if (safe_tile(old_x - 1, sl->enemy->y_pos[num], sl))
		{
			sl->level->map[old_y][old_x] = '0';
			sl->enemy->x_pos[num]--;
		}
		else
			sl->enemy->dir[num] = !sl->enemy->dir[num];
	}
}

static void	move_y(t_so_long *sl, int num)
{
	int	old_y;
	int	old_x;

	old_x = sl->enemy->x_pos[num];
	old_y = sl->enemy->y_pos[num];
	if (sl->enemy->dir[num] == 0)
	{
		if (safe_tile(old_x, old_y + 1, sl))
		{
			sl->level->map[old_y][old_x] = '0';
			sl->enemy->y_pos[num]++;
		}
		else
			sl->enemy->dir[num] = !sl->enemy->dir[num];
	}
	if (sl->enemy->dir[num] == 1)
	{
		if (safe_tile(old_x, old_y - 1, sl))
		{
			sl->level->map[old_y][old_x] = '0';
			sl->enemy->y_pos[num]--;
		}
		else
			sl->enemy->dir[num] = !sl->enemy->dir[num];
	}
}

void	move_enemies(t_so_long *sl)
{
	int	i;

	i = 0;
	if (sl->level->enemy_num != 0)
	{
		if (sl->enemy->move_frame == 0)
		{
			while (i < sl->level->enemy_num)
			{
				if (sl->enemy->x_axis_mov[i] == 1)
					move_x(sl, i);
				else
					move_y(sl, i);
				i ++;
				mlx_clear_window(sl->data->mlx_ptr, sl->data->win);
				draw_map(sl, 0, 0);
			}
		}
	}
}
