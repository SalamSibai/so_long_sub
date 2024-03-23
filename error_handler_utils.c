/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:08:13 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/04 18:36:20 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief frees malloced character double pointers
/// @param matrix the matrix
/// @param rows number of rows
void	free_char_matrix(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(matrix[i++]);
	free(matrix);
}

void	free_int_matrix(int **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(matrix[i++]);
	free(matrix);
}

void	free_matrix(t_node_info **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(matrix[i++]);
	free(matrix);
}

void	free_enemies(t_so_long *sl)
{
	if (sl->enemy)
	{
		if (sl->enemy->x_pos)
			free(sl->enemy->x_pos);
		if (sl->enemy->y_pos)
			free(sl->enemy->y_pos);
		if (sl->enemy->x_axis_mov)
			free(sl->enemy->x_axis_mov);
		if (sl->enemy->dir)
			free(sl->enemy->dir);
		free(sl->enemy);
	}
}
