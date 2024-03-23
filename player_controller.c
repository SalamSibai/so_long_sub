/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:56:16 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/28 21:51:15 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief gets movement direction
/// @param dr the movement value
/// @return if 1, moving right, if 2, moving up
//		if 3, moving left, and if 4, moving down
int	get_direction(int dr)
{
	if (dr == RIGHT || dr == D)
		return (1);
	else if (dr == UP || dr == W)
		return (2);
	else if (dr == LEFT || dr == A)
		return (3);
	else if (dr == DOWN || dr == S)
		return (4);
	return (0);
}

static int	safe_tile(int new_x, int new_y, t_so_long *sl)
{
	if ((new_y > 0 && new_y < (sl->level->rows - 1))
		&& (new_x > 0 && new_x < (sl->level->columns - 1))
		&& (sl->level->map[new_y][new_x] != '1'))
	{
		if (sl->level->map[new_y][new_x] == 'E')
			return (check_end(sl));
		else if (sl->level->map[new_y][new_x] == 'C')
			sl->player->collected ++;
		else if (sl->level->map[new_y][new_x] == 'M')
			close_window(sl);
		return (1);
	}
	else if (sl->level->map[new_y][new_x] == '1')
	{
		sl->player->pressed = 0;
		sl->printed = 0;
		print_moves(sl);
	}
	return (0);
}

/// @brief moves character along the x axis
/// @param player player struct
/// @param dir direction of movement
void	move_x(t_so_long *sl, int dir)
{
	int	old_x;
	int	old_y;

	old_y = sl->player->y_pos;
	old_x = sl->player->x_pos;
	if (dir == 1)
	{
		if (safe_tile(old_x + 1, old_y, sl) == 1)
		{
			sl->level->map[old_y][old_x] = '0';
			sl->player->x_pos ++;
			sl->level->map[sl->player->y_pos][sl->player->x_pos] = 'P';
			sl->player->moved = 1;
		}
	}
	else if (dir == -1)
	{
		if (safe_tile(old_x - 1, old_y, sl) == 1)
		{
			sl->level->map[old_y][old_x] = '0';
			sl->player->x_pos --;
			sl->level->map[sl->player->y_pos][sl->player->x_pos] = 'P';
			sl->player->moved = 1;
		}
	}
}

/// @brief moves player along the y axis
/// @param player player struct
/// @param dir direction of movement
void	move_y(t_so_long *sl, int dir)
{
	int	old_x;
	int	old_y;

	old_y = sl->player->y_pos;
	old_x = sl->player->x_pos;
	if (dir == 1)
	{
		if (safe_tile(old_x, old_y - 1, sl) == 1)
		{
			sl->level->map[old_y][old_x] = '0';
			sl->player->y_pos --;
			sl->level->map[sl->player->y_pos][sl->player->x_pos] = 'P';
			sl->player->moved = 1;
		}
	}
	else if (dir == -1)
	{
		if (safe_tile(old_x, old_y + 1, sl) == 1)
		{
			sl->level->map[old_y][old_x] = '0';
			sl->player->y_pos ++;
			sl->level->map[sl->player->y_pos][sl->player->x_pos] = 'P';
			sl->player->moved = 1;
		}
	}
}

void	player_movement(t_so_long *sl)
{
	int	dir;

	dir = get_direction(sl->player->move_dr);
	if (dir == 1)
		move_x(sl, 1);
	else if (dir == 3)
		move_x(sl, -1);
	else if (dir == 2)
		move_y(sl, 1);
	else if (dir == 4)
		move_y(sl, -1);
}
