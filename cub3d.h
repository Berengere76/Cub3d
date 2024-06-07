/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:41 by blebas            #+#    #+#             */
/*   Updated: 2024/06/07 12:09:20 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ***************** */
/*      INCLUDES     */
/* ***************** */

# include <fcntl.h>
# include "minilibx/mlx42.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h> //TODO REMOVE (printf)

/* ***************** */
/*        Kiri       */
/* ***************** */

# define WIN_W 640
# define WIN_H 512
# define BLOCK_RES 64

/* ***************** */
/*     STRUCTURES    */
/* ***************** */

typedef struct colour
{
	int	R;
	int	G;
	int	B;
}		t_colour;

typedef struct s_data
{
	void		*mlx;
	int			width;
	int			height;
	double		posX; //start position of the player
	double		posY;
	double		dirX; //start direction of player's POV
	double		dirY;
	double		planeX; //camera plane
	double		planeY;
	char		*NO_texture;
	char		*SO_texture;
	char		*WE_texture;
	char		*EA_texture;
	t_colour	floor;
	t_colour	ceiling;
	mlx_image_t *img;
}	t_data;

typedef struct s_gridpos
{
	double		x;
	double		y;
}	t_gridpos;

/* TEXTURE.C */
int32_t   	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_draw_square(t_data *data, int x, int y, int width);
void		init_img(t_data *data);
void		ft_put_pixel_to_background(t_data *data);
void		ft_draw_minimap(t_data *data);

/* MOVEMENTS.C */
void		get_player_pos(t_data *data);
void		put_player_on_minimap(t_data *data, int x, int y);

/* PARSE_INPUT.C */
int	open_cub(char *argv);

/* CHECK_MAP.C */
int		ft_error(char *type, char *message);
int		is_direc(char c);
int		is_valid(char c);
int		check_0(char **map, int row, int col);
int		map_open(char **map);

/* PARSE_MAP.C */
int		parse_map(t_data *data, char **map);

/* MAIN.C */

#endif
