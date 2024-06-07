/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:41 by blebas            #+#    #+#             */
/*   Updated: 2024/06/07 11:31:08 by kcouchma         ###   ########.fr       */
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

typedef struct walltexture
{
	mlx_texture_t	*no_walltexture;
	mlx_texture_t	*so_walltexture;
	mlx_texture_t	*we_walltexture;
	mlx_texture_t	*ea_walltexture;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
}		t_walltexture;

typedef struct s_data
{
	void			*mlx;
	int				width;
	int				height;
	double			posx; //start position of the player
	double			posy;
	double			dirx; //start direction of player's POV
	double			diry;
	double			planex; //camera plane
	double			planey;
	t_walltexture	walltexture;
	char			**map;
	t_image			image;
	t_texture		texture;
	int				floor;
	int				ceiling;
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

/* PARSE_INPUT.C */
int		open_cub(char *argv, t_data *data);

/* CHECK_MAP.C */
bool	is_spc(char c);
bool	is_direc(char c);
bool	is_valid(char c);
bool	check_0(char **map, size_t row, size_t col);
int		map_is_open(t_data *data);

/* ERROR.C */
void	ft_free(t_data *data);
int		ft_errorfree(char *type, char *message, t_data *data);
// int		ft_error(char *type, char *message);

/* PARSE_MAP.C */
int		parse_map(t_data *data);

/* MAIN.C */
void	error(void);

/* GNL.C */
char	*gnl(int fd);

/* GNL_UTILS.C */
int		ft_findnl(char *buffer);
char	*ft_strcpy(char *str1, char *str2);

/* GET_COLOURS.C */
int		get_colours(char *line, t_data *data);

/* GET_TEXTURES.C */
int		get_textures(char *line, t_data *data);

/* GET_MAP.C */
bool	is_not_last(t_data *data);
int		get_map(char *line, t_data *data);

#endif
