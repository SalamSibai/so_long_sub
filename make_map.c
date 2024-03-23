/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:21:50 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/04 18:39:33 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_flag_tiles(t_so_long *sl, int *len)
{
	sl->level->tiles->exit[0] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/exit/flag0.xpm", len, len);
	if (!sl->level->tiles->exit[0])
		error_handler(NULL, sl, "no exit tile image\n", 1);
	sl->level->tiles->exit[1] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/exit/flag1.xpm", len, len);
	if (!sl->level->tiles->exit[1])
		error_handler(NULL, sl, "no exit tile image\n", 1);
	sl->level->tiles->exit[2] = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/exit/flag2.xpm", len, len);
	if (!sl->level->tiles->exit[2])
		error_handler(NULL, sl, "no exit tile image\n", 1);
}

void	set_tiles(t_so_long *sl, int *len)
{
	set_player_anims(sl, len);
	set_enemy_tiles(sl, len);
	sl->level->tiles->wall = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/star.xpm", len, len);
	if (!sl->level->tiles->wall)
		error_handler(NULL, sl, "no wall tile image\n", 1);
	sl->level->tiles->empty = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/empty.xpm", len, len);
	if (!sl->level->tiles->empty)
		error_handler(NULL, sl, "no empty tile image\n", 1);
	sl->level->tiles->collectable = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/at.xpm", len, len);
	if (!sl->level->tiles->collectable)
		error_handler(NULL, sl, "no collectable tile image\n", 1);
	set_flag_tiles(sl, len);
	sl->level->tiles->edges = mlx_xpm_file_to_image(sl->data->mlx_ptr,
			"sprites/xpmfiles/64*64/round.xpm", len, len);
	if (!sl->level->tiles->edges)
		error_handler(NULL, sl, "no edges tile image\n", 1);
}

int	put_edge(t_level *level, int row, int col)
{
	if ((row == 0 && col == 0)
		|| (row == 0 && col == level->columns - 1)
		|| (row == level->rows - 1 && col == 0)
		|| (row == level->rows - 1 && col == level->columns - 1))
		return (1);
	return (0);
}

void	draw_map(t_so_long *sl, int row, int column)
{
	int	enemy_ctr;

	enemy_ctr = -1;
	row = -1;
	while (++row < sl->level->rows)
	{
		column = -1;
		while (++column < sl->level->columns)
		{
			put_img(sl->data, sl->level->tiles->empty, column, row);
			if (put_edge(sl->level, row, column))
				put_img(sl->data, sl->level->tiles->edges, column, row);
			else if (sl->level->map[row][column] == '1')
				put_img(sl->data, sl->level->tiles->wall, column, row);
			else if (sl->level->map[row][column] == 'C')
				put_img(sl->data, sl->level->tiles->collectable, column, row);
			else if (sl->level->map[row][column] == 'M' && sl->start == 0)
				initial_monster_draw(sl, row, column, &enemy_ctr);
			else if (sl->level->map[row][column] == 'E' && sl->start == 0)
				initial_exit_draw(sl, row, column);
			else if (sl->level->map[row][column] == 'P' && sl->start == 0)
				initial_player_draw(sl, row, column);
		}
	}
}

void	make_map(t_so_long *sl)
{
	int	len;
	int	i;

	i = -1;
	len = TILE_SIZE;
	sl->level->tiles = malloc(sizeof (t_tile));
	if (!sl->level->tiles)
		error_handler(NULL, sl, "Error: No space for level tiles\n", 1);
	while (++i < 4)
		sl->level->tiles->player[i] = NULL;
	set_tiles(sl, &len);
	draw_map(sl, 0, 0);
}
