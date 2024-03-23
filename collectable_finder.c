/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:02:07 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/03 22:35:17 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief adds the direction the node was visited in
/// @param level level pointer
/// @param direction direction towards
/// @param x x pos
/// @param y y pos
/// @return 0 if it fails to add the direction
static int	set_dir(t_level *level, int direction, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (level->visited[x][y].dir[i] != 0)
		{
			if (level->visited[x][y].dir[i] == direction)
				return (0);
		}
		else if (level->visited[x][y].dir[i] == 0)
		{
			level->visited[x][y].dir[i] = direction;
			return (1);
		}
		i ++;
	}
	return (0);
}

/// @brief collects towards the right till it reaches a wall or the exit
/// @param level level struct variable
/// @param step_ctr counts the steps taken
/// @return 1 if there are steps that have been taken.
///	for dir: when visiting from the right, dir = 1
int	collect_right(t_level *level, int x, int y, int *step_ctr)
{
	if (level->init_map[x][y + 1] == '1'
		|| level->init_map[x][y + 1] == 'E')
	{
		if (!set_dir(level, 1, x, y))
			return (-1);
		return (y);
	}
	else if (level->init_map[x][y] == 'C')
	{
		level->found_coll ++;
		level->init_map[x][y] = '0';
	}
	y ++;
	(*step_ctr)++;
	return (collect_right(level, x, y, step_ctr));
}

/// @brief collects forward till it reaches a wall or the exit
/// @param level level struct variable
/// @param step_ctr counts the steps taken
/// @return 1 if there are steps that have been taken.
///	for dir: when visiting from the right, dir = 2
int	collect_down(t_level *level, int x, int y, int *step_ctr)
{
	if (level->init_map[x + 1][y] == '1'
		|| level->init_map[x + 1][y] == 'E')
	{
		if (!set_dir(level, 2, x, y))
			return (-1);
		return (x);
	}
	else if (level->init_map[x][y] == 'C')
	{
		level->found_coll ++;
		level->init_map[x][y] = '0';
	}
	x ++;
	(*step_ctr)++;
	return (collect_down(level, x, y, step_ctr));
}

/// @brief collects to the left till it reaches a wall or the exit
/// @param level level struct variable
/// @param step_ctr counts the steps taken
/// @return 1 if there are steps that have been taken.
///	for dir: when visiting from the right, dir = 3
int	collect_left(t_level *level, int x, int y, int *step_ctr)
{
	if (level->init_map[x][y - 1] == '1'
		|| level->init_map[x][y - 1] == 'E')
	{
		if (!set_dir(level, 3, x, y))
			return (-1);
		return (y);
	}
	else if (level->init_map[x][y] == 'C')
	{
		level->found_coll ++;
		level->init_map[x][y] = '0';
	}
	y --;
	(*step_ctr)++;
	return (collect_left(level, x, y, step_ctr));
}

/// @brief collects downwards till it reaches a wall or the exit
/// @param level level struct variable
/// @param step_ctr counts the steps taken
/// @return 1 if there are steps that have been taken.
///	for dir: when visiting from the right, dir = 4
int	collect_forward(t_level *level, int x, int y, int *step_ctr)
{
	if (level->init_map[x - 1][y] == '1'
		|| level->init_map[x - 1][y] == 'E')
	{
		if (!set_dir(level, 4, x, y))
			return (-1);
		return (x);
	}
	else if (level->init_map[x][y] == 'C')
	{
		level->found_coll ++;
		level->init_map[x][y] = '0';
	}
	x --;
	(*step_ctr)++;
	return (collect_forward(level, x, y, step_ctr));
}
