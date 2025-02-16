NAME		= so_long
CC			= cc -g
CFLAGS		= -Wall -Wextra -Werror -Imlx_linux -O3 -DESC=65307 -DW=119 -DS=115 -DA=97 -DD=100 -DRIGHT=65363 -DLEFT=65361
MLXFLAG		= -Imlx_linux -lXext -lX11 -lm -lz
SRC			=	src/access.c			\
				src/control.c			\
				src/exit.c				\
				src/get_next_line.c		\
				src/initialization.c	\
				src/map_creat.c			\
				src/position.c			\
				src/so_long.c
LIBFT		= libft/libft.a
FT_PRINTF	= ft_printf/libftprintf.a
MLX			= minilibx/libmlx.a
OBJ_DIR		= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(MLX) $(LIBFT) $(FT_PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(FT_PRINTF) $(MLX) $(MLXFLAG)

$(OBJ_DIR)/%.o:	%.c
	mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

$(FT_PRINTF):
	@make -C ft_printf

$(MLX):
	@make -C minilibx

clean:
	@make -C libft clean
	@make -C ft_printf clean
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@make -C minilibx clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
