SO_LONG		= so_long

BONUS		= bonus

CC      	= clang

CFLAGS		= -Wall -Werror -Wextra -g

RM		= rm -rf

LIBFT		= ./libft/libft.a

MLX_DIR:= ./minilibx-linux
MLX		= $(MLX_DIR)/libmlx.a

MLXFLAGS	= -lX11 -lXext -lm -lbsd

SRC		= $(wildcard src/*.c)

OBJ		= $(SRC:.c=.o)

SRC_B		= $(wildcard bonus/*.c)

OBJ_B		= $(SRC_B:.c=.o)

all: $(SO_LONG)

$(SO_LONG): $(OBJ) $(SRC) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC) $(MLX) $(LIBFT) -o so_long

$(BONUS): $(OBJ_B) $(SRC_B) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC_B) $(MLX) $(LIBFT) -o so_long_b
	
$(LIBFT):
	$(MAKE) -C ./libft

$(MLX):	
	$(MAKE) -C ./minilibx-linux

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(OBJ)
	$(RM) $(OBJ_B)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SO_LONG) ./so_long_b
	
re:	fclean all
