NAME := cub3d

CC := cc
CFLAGS		= -g -Wall -Wextra -Werror
CLINKS		= -ldl -lglfw -pthread -lm
MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

FT			= Libft
LIBFT		= $(FT)/libft.a

SOURCE :=	main.c			\
			texture.c		\
			parse_map.c		\
			check_map.c		\
			parse_input.c	\
			error.c			\
			gnl.c

OBJ 	= $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	cmake $(MLX) -B $(MLX)	
	$(MAKE) -C $(MLX)
	
$(LIBFT): $(FT)
	$(MAKE) -C $(FT)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
		make clean -C $(MLX)
		rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re
