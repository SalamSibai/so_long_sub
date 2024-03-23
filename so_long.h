/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:08:20 by ssibai            #+#    #+#             */
/*   Updated: 2024/03/10 15:20:14 by ssibai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define TILE_SIZE 64
# define ANIM_FRAME 10

typedef enum keys
{
	ESC = 53,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	W = 13,
	A = 0,
	S = 1,
	D = 2
}	t_keys;

typedef struct s_tile
{
	void	*collectable;
	void	*wall;
	void	*empty;
	void	*edges;
	void	*exit[3];
	void	*player[4];
	void	*enemy[2];
}	t_tile;

typedef struct s_node_info
{
	int	dir[4];
}	t_node_info;

typedef struct s_level
{
	int			flag_frame;
	int			reverse_flag;
	int			exit_x;
	int			exit_y;
	int			rows;
	int			columns;
	int			collect_num;
	int			enemy_num;
	char		*file;
	char		**map;
	char		**init_map;
	int			found_coll;
	int			**collectible;
	t_node_info	**visited;
	t_tile		*tiles;
}	t_level;

typedef struct s_player
{
	int	moves_no;
	int	move_dr;
	int	collected;
	int	x_pos;
	int	y_pos;
	int	pressed;
	int	anim_loop;
	int	blink_ctr;
	int	blink_frame;
	int	moved;
}	t_player;

typedef struct s_enemy
{
	int	*x_pos;
	int	*y_pos;
	int	*x_axis_mov;
	int	open_frame;
	int	*dir;
	int	move_frame;
}	t_enemy;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
}	t_mlx_data;

typedef struct s_so_long
{
	int			start;
	int			frame;
	int			printed;
	t_mlx_data	*data;
	t_player	*player;
	t_level		*level;
	t_enemy		*enemy;
}	t_so_long;

/* ************************************************************************** */
/* 									parsing									  */
/* ************************************************************************** */

int		init_level(t_level *level);
int		reset_visited(t_level *level, int malloced);
char	find_startpoint(t_level *level, int *start_x, int *start_y);
int		check_path(t_level *level, int start_x, int start_y);
int		check_coll(t_level *level, int start_x, int start_y);
char	*open_read_level(char *level_path, char *file);
void	validate_level(char *level_path, t_so_long *sl);
int		loop_right(t_level *level, int x, int y, int *step_ctr);
int		loop_forward(t_level *level, int x, int y, int *step_ctr);
int		loop_left(t_level *level, int x, int y, int *step_ctr);
int		loop_down(t_level *level, int x, int y, int *step_ctr);
int		init_node_info(t_level *level, int i, int j);
int		collect_right(t_level *level, int x, int y, int *step_ctr);
int		collect_down(t_level *level, int x, int y, int *step_ctr);
int		collect_left(t_level *level, int x, int y, int *step_ctr);
int		collect_forward(t_level *level, int x, int y, int *step_ctr);
int		init_col_pos(t_level *level);

/* ************************************************************************** */
/* 									so_long									  */
/* ************************************************************************** */

void	so_long(t_so_long *so_long);
void	initialize(t_so_long *sl);
void	init_enemy(t_so_long *sl);
void	make_map(t_so_long *sl);
int		check_end(t_so_long *sl);

/* ************************************************************************** */
/* 								window_handling								  */
/* ************************************************************************** */

int		close_window(t_so_long *sl);
void	print_moves(t_so_long *sl);

/* ************************************************************************** */
/* 								player_controller							  */
/* ************************************************************************** */

void	set_player_anims(t_so_long *sl, int *len);
void	draw_player(t_so_long *sl, int frame);
void	player_movement(t_so_long *sl);
void	beginning_anim(t_so_long *sl);
void	blink_anim(t_so_long *sl);
void	print_moves_to_window(t_so_long *sl);

/* ************************************************************************** */
/* 							error handling & cleanup						  */
/* ************************************************************************** */

void	free_enemies(t_so_long *sl);
void	free_char_matrix(char **matrix, int rows);
void	free_int_matrix(int **matrix, int rows);
void	free_matrix(t_node_info **matrix, int rows);
void	free_tiles(t_tile *tiles, void **tile, int num, char type);
void	cleanup(t_so_long *sl);
void	error_handler(char *file, t_so_long *sl, char *err_msg, int clean);
void	destroy_images(t_so_long *sl, t_tile *tiles);

/* ************************************************************************** */
/* 									animations								  */
/* ************************************************************************** */

void	decrement_frame_ctr(t_so_long *sl);
void	set_flag_tiles(t_so_long *sl, int *len);
void	flag_anim(t_so_long *sl);

/* ************************************************************************** */
/* 								drawing and print							  */
/* ************************************************************************** */

void	put_img(t_mlx_data *mlx, void *img, int col, int row);
void	print_moves(t_so_long *sl);
void	draw_flag(t_so_long *sl, int frame);
void	draw_map(t_so_long *sl, int row, int column);
void	draw_enemy(t_so_long *sl, int frame, int num);
void	set_enemy_tiles(t_so_long *sl, int *len);
void	enemy_anim(t_so_long *sl);
void	initial_exit_draw(t_so_long *sl, int row, int column);
void	initial_monster_draw(t_so_long *sl, int row, int column, int *ctr);
void	initial_player_draw(t_so_long *sl, int row, int column);

/* ************************************************************************** */
/* 									ENEMY									  */
/* ************************************************************************** */

void	enemy_movement(t_so_long *sl, int num);
void	move_enemies(t_so_long *sl);
void	check_pos(t_so_long *sl);

#endif