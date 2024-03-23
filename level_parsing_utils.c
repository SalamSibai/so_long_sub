/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:13:45 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/10 15:14:13 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	reset_visited(t_level *level, int malloced)
{
	int	i;
	int	j;

	i = -1;
	if (!malloced)
	{
		if (!init_node_info(level, 0, 0))
			return (0);
	}
	else
	{
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
	}
	return (1);
}

int	check_coll(t_level *lvl, int start_x, int start_y)
{
	int	rctr;
	int	lctr;
	int	fctr;
	int	bctr;

	bctr = 0;
	fctr = 0;
	lctr = 0;
	rctr = 0;
	if (lvl->found_coll == lvl->collect_num)
		return (1);
	if (start_x == -1 || start_y == -1)
		return (0);
	else if (start_x < 0 || start_y < 0
		|| start_x >= lvl->rows || start_y >= lvl->columns)
		return (0);
	return (check_coll(lvl, start_x, collect_right(lvl, start_x, start_y, &rctr))
		|| check_coll(lvl, start_x, collect_left(lvl, start_x, start_y, &lctr))
		|| check_coll(lvl, collect_forward(lvl, start_x, start_y, &fctr), start_y)
		|| check_coll(lvl, collect_down(lvl, start_x, start_y, &bctr), start_y));
}

int	check_path(t_level *lvl, int start_x, int start_y)
{
	int	rctr;
	int	lctr;
	int	fctr;
	int	bctr;

	bctr = 0;
	fctr = 0;
	lctr = 0;
	rctr = 0;
	if (start_x == -1 || start_y == -1)
		return (0);
	if (lvl->map[start_x][start_y] == 'E')
		return (1);
	else if (start_x < 0 || start_y < 0
		|| start_x >= lvl->rows || start_y >= lvl->columns)
		return (0);
	return (check_path(lvl, start_x, loop_right(lvl, start_x, start_y, &rctr))
		|| check_path(lvl, start_x, loop_left(lvl, start_x, start_y, &lctr))
		|| check_path(lvl, loop_forward(lvl, start_x, start_y, &fctr), start_y)
		|| check_path(lvl, loop_down(lvl, start_x, start_y, &bctr), start_y));
}

char	find_startpoint(t_level *level, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (level->map[i] != NULL)
	{
		j = 0;
		while (level->map[i][j] != '\0')
		{
			if (level->map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ('E');
			}
			j ++;
		}
		i ++;
	}
	return ('\0');
}

char	*open_read_level(char *level_path, char *file)
{
	int		fd;
	char	*temp;
	char	buf[BUFFER_SIZE + 1];
	size_t	red;

	fd = open(level_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	red = read(fd, buf, BUFFER_SIZE);
	while (red > 0)
	{
		buf[red] = '\0';
		if (file)
		{
			temp = file;
			file = ft_strjoin(file, buf);
			free (temp);
		}
		else
			file = ft_strdup(buf);
		red = read(fd, buf, BUFFER_SIZE);
	}
	close(fd);
	return (file);
}
