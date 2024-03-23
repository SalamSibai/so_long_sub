/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:53:17 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/04 20:00:16 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_col_pos(t_level *level)
{
	int	i;
	int	j;

	i = -1;
	level->collectible = malloc(level->rows * (sizeof(int *)));
	if (!level->collectible)
		return (0);
	while (++i < level->rows)
	{
		level->collectible[i] = malloc(level->columns * sizeof(int));
		if (!level->collectible[i])
			return (0);
	}
	i = -1;
	while (level->map[++i])
	{
		j = -1;
		while (level->map[i][++j])
		{
			level->collectible[i][j] = 0;
			if (level->map[i][j] == 'C')
				level->collectible[i][j] = 1;
		}
	}
	return (1);
}

int	init_node_info(t_level *level, int i, int j)
{
	i = -1;
	j = -1;
	level->visited = malloc((level->rows) * sizeof(t_node_info *));
	if (!level->visited)
		return (0);
	while (++i < level->rows)
	{
		level->visited[i] = malloc(level->columns * sizeof (t_node_info));
		if (!level->visited[i])
			return (0);
	}
	i = -1;
	while (++i < level->rows)
	{
		j = -1;
		while (++j < level->columns)
		{
			level->visited[i][j].dir[0] = 0;
			level->visited[i][j].dir[1] = 0;
			level->visited[i][j].dir[2] = 0;
			level->visited[i][j].dir[3] = 0;
		}
	}
	return (1);
}

int	init_level(t_level *level)
{
	int	i;

	i = -1;
	level->flag_frame = 0;
	level->reverse_flag = 0;
	level->rows = 0;
	level->columns = 0;
	level->collect_num = 0;
	level->enemy_num = 0;
	level->map = NULL;
	level->init_map = NULL;
	level->visited = NULL;
	level->found_coll = 0;
	level->collectible = NULL;
	level->tiles = NULL;
	return (1);
}
