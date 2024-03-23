/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:27:19 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/04 18:32:54 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief adds the direction the node was visited in
/// @param level level pointer
/// @param direction direction towards
/// @param x x pos
/// @param y y pos
/// @return 0 if it fails to add the direction 
int	set_dir(t_level *level, int direction, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (level->visited[x][y].dir[i] != 0)
		{
			if (direction == level->visited[x][y].dir[i])
				return (0);
			i++;
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

/// @brief loops towards the right till it reaches a wall or the exit
/// @param level level struct variable
/// @param step_ctr counts the steps taken
/// @return 1 if there are steps that have been taken.
///	for dir: when visiting from the right, dir = 1
int	loop_right(t_level *level, int x, int y, int *step_ctr)
{
	if (level->map[x][y + 1] == '1')
	{
		if (step_ctr == 0)
			return (y);
		if (!set_dir(level, 1, x, y))
			return (-1);
		return (y);
	}
	else if (level->map[x][y + 1] == 'E')
		return (y + 1);
	y ++;
	(*step_ctr)++;
	return (loop_right(level, x, y, step_ctr));
}

/// @brief loops forward till it reaches a wall or the exit
/// @param level level struct variable
/// @param step_ctr counts the steps taken
/// @return 1 if there are steps that have been taken.
///	for dir: when visiting from the right, dir = 2
int	loop_down(t_level *level, int x, int y, int *step_ctr)
{
	if (level->map[x + 1][y] == '1')
	{
		if (step_ctr == 0)
			return (x);
		if (!set_dir(level, 2, x, y))
			return (-1);
		return (x);
	}
	else if (level->map[x + 1][y] == 'E')
		return (x + 1);
	x ++;
	(*step_ctr)++;
	return (loop_down(level, x, y, step_ctr));
}

/// @brief loops to the left till it reaches a wall or the exit
/// @param level level struct variable
/// @param step_ctr counts the steps taken
/// @return 1 if there are steps that have been taken.
///	for dir: when visiting from the right, dir = 3
int	loop_left(t_level *level, int x, int y, int *step_ctr)
{
	if (level->map[x][y - 1] == '1')
	{
		if (step_ctr == 0)
			return (y);
		if (!set_dir(level, 3, x, y))
			return (-1);
		return (y);
	}
	else if (level->map[x][y - 1] == 'E')
		return (y - 1);
	y --;
	(*step_ctr)++;
	return (loop_left(level, x, y, step_ctr));
}

/// @brief loops downwards till it reaches a wall or the exit
/// @param level level struct variable
/// @param step_ctr counts the steps taken
/// @return 1 if there are steps that have been taken.
///	for dir: when visiting from the right, dir = 4
int	loop_forward(t_level *level, int x, int y, int *step_ctr)
{
	if (level->map[x - 1][y] == '1')
	{
		if (step_ctr == 0)
			return (x);
		if (!set_dir(level, 4, x, y))
			return (-1);
		return (x);
	}
	else if (level->map[x - 1][y] == 'E')
		return (x - 1);
	x --;
	(*step_ctr)++;
	return (loop_forward(level, x, y, step_ctr));
}
