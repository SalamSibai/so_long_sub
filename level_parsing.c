/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:07:41 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/04 18:31:24 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief checks whether the level is surrounded by walls
/// @param level 5_level variable pointer
/// @return 1 for closed, 0 for open
int	is_closed(t_level	*level)
{
	int	i;

	i = 0;
	while (level->map[0][i] != '\0')
	{
		if (level->map[0][i++] != '1')
			return (0);
	}
	i = 0;
	while (level->map[level->rows -1][i] != '\0')
	{
		if (level->map[level->rows -1][i++] != '1')
			return (0);
	}
	i = 0;
	while (level->map[i] != NULL)
	{
		if ((level->map[i][0] != '1')
			|| (level->map[i][level->columns - 1] != '1'))
			return (0);
		else
			i++;
	}
	return (1);
}

/// @brief checks whether level is rectangular or not
/// @param level t_level variable pointer
/// @return 1 for rectangular, 0 for not rectangular
int	is_rectangular(t_level	*level)
{
	int	i;
	int	j;

	i = 0;
	while (level->map[i] != NULL)
	{
		j = 0;
		while (level->map[i][j] != '\0')
			j ++;
		if (i == 0)
			level->columns = j;
		else
			if (level->columns != j)
				return (0);
		i++ ;
	}
	level->rows = i;
	return (1);
}

/// @brief checks whether the required content exists within the level's map
/// @param full_file the level as a single string
/// @return 1 if it contains all needed content, 0 for invalid
int	valid_content(char *file, t_level *level)
{
	int	exit;
	int	player;
	int	i;

	exit = 0;
	player = 0;
	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == 'C')
			level->collect_num ++;
		else if (file[i] == 'E')
			exit ++;
		else if (file[i] == 'P')
			player ++;
		else if (file[i] == 'M')
			level->enemy_num ++;
		else if (file[i] != '1' && file[i] != '0' && file[i] != '\n')
			return (0);
		i++;
	}
	if ((level->collect_num == 0) || (exit != 1) || (player != 1))
		return (0);
	return (1);
}

/// @brief 
/// @param level 
/// @return 
int	valid_path(t_level *level, int i, int j)
{
	int	start_x;
	int	start_y;

	start_x = 0;
	start_y = 0;
	if (!init_col_pos(level) || !reset_visited(level, 0)
		|| find_startpoint(level, &start_x, &start_y) == '\0'
		|| !check_coll(level, start_x, start_y))
		return (0);
	reset_visited(level, 1);
	while (level->map[++i])
	{
		j = -1;
		while (level->map[i][++j])
		{
			if (level->collectible[i][j] == 1)
			{
				if (!check_path(level, i, j))
					return (0);
				reset_visited(level, 1);
			}
		}
	}
	return (1);
}

/// @brief checking whether the level is valid or not
/// @param level_path path of the level
/// @param level the t_level variable
/// @param full_file the full file stored in a single string
/// @return returns the level that is in the level path if valid,
//			NULL otherwise
void	validate_level(char *level_path, t_so_long *sl)
{
	char	*full_file;

	if (ft_strncmp((level_path + (ft_strlen(level_path) - 4)), ".ber", 4) != 0)
		error_handler(NULL, sl, "Error: file type is wrong\n", 1);
	full_file = open_read_level(level_path, 0);
	if (!full_file)
		error_handler(full_file, sl, "Error: couldn't open file\n", 1);
	if (valid_content(full_file, sl->level) == 0)
		error_handler(full_file, sl, "Error: content is incorrect\n", 1);
	sl->level->map = ft_split(full_file, '\n');
	sl->level->init_map = ft_split(full_file, '\n');
	if (is_rectangular(sl->level) == 0)
		error_handler(full_file, sl, "Error: level is not a rectangle\n", 1);
	if (is_closed(sl->level) == 0)
		error_handler(full_file, sl, "Error: level is not closed\n", 1);
	if (valid_path(sl->level, -1, -1) == 0)
		error_handler(full_file, sl,
			"Error: there is no valid path to exit or collectables\n", 1);
	free (full_file);
}
