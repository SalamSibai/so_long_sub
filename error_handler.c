/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:51:42 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/04 18:36:25 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_level(t_so_long *sl, t_level *level)
{
	free_char_matrix(level->map, level->rows);
	free_char_matrix(level->init_map, level->rows);
	if (sl->level->collectible)
		free_int_matrix(level->collectible, level->rows);
	if (sl->level->visited)
		free_matrix(level->visited, level->rows);
	free_enemies(sl);
	if (level->tiles)
	{
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->collectable);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->edges);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->empty);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->exit[0]);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->exit[1]);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->exit[2]);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->wall);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->enemy[0]);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->enemy[1]);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->player[0]);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->player[1]);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->player[2]);
		mlx_destroy_image(sl->data->mlx_ptr, level->tiles->player[3]);
	}
	free(level->tiles);
	free(level);
}

void	cleanup(t_so_long *sl)
{
	if (sl->level)
		cleanup_level(sl, sl->level);
	if (sl->player)
		free(sl->player);
	if (sl->data)
	{
		free(sl->data->mlx_ptr);
		free(sl->data);
	}
	free (sl);
}

/// @brief error handling function
/// @param sl t_so_long pointer
/// @param err_msg error msg
/// @param clean clean flag
void	error_handler(char *file, t_so_long *sl, char *err_msg, int clean)
{
	free (file);
	ft_putstr_fd(err_msg, 2);
	if (clean == 1)
		cleanup(sl);
	exit(0);
}
