/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:41 by blebas            #+#    #+#             */
/*   Updated: 2024/06/05 17:11:28 by kcouchma         ###   ########.fr       */
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
/*       COLORS      */
/* ***************** */

# define NC		"\e[0m"
# define YELLOW	"\e[1;33m"
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define PURPLE	"\e[1;35m"
# define CYAN	"\e[1;36m"
# define BLUE	"\e[1;34m"

/* ***************** */
/*        Kiri       */
/* ***************** */

# define WIN_W 640
# define WIN_H 512
# define BLOCK_RES 64

/* ***************** */
/*     STRUCTURES    */
/* ***************** */

typedef struct image
{
	mlx_image_t	*background;
}		t_image;

typedef struct texture
{
	mlx_texture_t	*background_texture;
}		t_texture;

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
	t_image		image;
	t_texture	texture;
	t_colour	floor;
	t_colour	ceiling;
}	t_data;

typedef struct s_gridpos
{
	double		x;
	double		y;
}	t_gridpos;

/* TEXTURE.C */
void	ft_loadpng(t_data *data);
void	ft_texture_image(t_data *data);
void	ft_resize(t_data *data);
void	ft_image(t_data *data);

/* CHECK_MAP.C */
int		map_error(char *message);
int		is_direc(char c);
int		is_valid(char c);
int		check_0(char **map, int row, int col);
int		map_open(char **map);

/* PARSE_MAP.C */
int		parse_map(t_data *data, char **map);

/* MAIN.C */
void	error(void);

#endif
