NAME		=	so_long

BONUS_NAME 	= so_long_bonus

MAND_SL		= so_long.c

BONUS_SL 	= so_long_bonus.c

FILES		=	initialize.c \
			level_parsing.c level_parsing_utils.c make_map.c make_map_utils.c \
			window_handler.c error_handler.c error_handler_utils.c \
			player_controller.c player_graphics.c \
			level_anim.c level_draw.c \
			enemy.c end_game.c path_finder.c collectable_finder.c level_init.c \

OBJS 		=	$(FILES:.c=.o)

MAND_OBJ	= $(MAND_SL:.c=.o)

BONUS_OBJ	= $(BONUS_SL:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

LIBFT = libft/libft.a

FTPRINTF = ft_printf/libftprintf.a

MLX = mlx/libmlx.a

MLX_FLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) :	$(MAND_OBJ) $(OBJS) $(LIBFT) $(FTPRINTF) $(MLX)
	$(CC)	$(CFLAGS) $(MAND_OBJ) $(OBJS) $(MLX_FLAGS) -o $@ $(LIBFT) $(FTPRINTF) $(MLX)
	rm -f $(BONUS_OBJ)

$(FTPRINTF):
	$(MAKE) -C ft_printf
$(LIBFT):
	$(MAKE) -C libft
$(MLX):
	$(MAKE) -C mlx

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ) $(OBJS) $(LIBFT) $(FTPRINTF) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJS) $(MLX_FLAGS) -o $@ $(LIBFT) $(FTPRINTF) $(MLX)
	rm -f $(MAND_OBJ)

$(FTPRINTF):
	$(MAKE) -C ft_printf

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C mlx

	
clean :
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C mlx clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJ)
	rm -f $(MAND_OBJ)
		
fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re:	fclean all
 
.PHONY: all clean fclean re
