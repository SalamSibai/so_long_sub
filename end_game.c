/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:10:19 by ssibai            #+#    #+#             */
/*   Updated: 2024/02/29 16:52:03 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_end(t_so_long *sl)
{
	if (sl->player->collected != sl->level->collect_num)
	{
		sl->player->pressed = 0;
		print_moves(sl);
		return (0);
	}
	else
	{
		print_moves(sl);
		ft_printf(" ./. !!YOU WIN!!! ./.\n");
		close_window(sl);
	}
	return (0);
}

void	player_death(t_so_long *sl)
{
	sl->start = 0;
	close_window(sl);
}

void	check_pos(t_so_long *sl)
{
	int	i;

	i = 0;
	while (i < sl->level->enemy_num)
	{
		if ((sl->enemy->x_pos[i] == sl->player->x_pos)
			&& (sl->enemy->y_pos[i] == sl->player->y_pos))
		{
			if (sl->player->pressed)
				print_moves(sl);
			ft_printf("!!YOU DIED!!\n");
			close_window(sl);
		}
		i ++;
	}
}
