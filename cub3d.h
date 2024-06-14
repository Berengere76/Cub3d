/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:41 by blebas            #+#    #+#             */
/*   Updated: 2024/06/14 12:39:06 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ***************** */
/*      INCLUDES     */
/* ***************** */

# include <fcntl.h>
# include <math.h>
# include "minilibx/mlx42.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <stdio.h> //TODO REMOVE (printf)

# define MOVESPEED 4.0f

/* ***************** */
/*      DEFINES      */
/* ***************** */

# define WIN_W 640
# define WIN_H 480
# define BLOCK_RES 64 // height/width/depth of walls (and all other cubes)
# define FOV_RAD 1.0472 // 60 degree FOV in radians
# define DIS_PROJ (WIN_W / 2) / tan(FOV_RAD / 2) //distance to projection plan

/* ***************** */
/*     STRUCTURES    */
/* ***************** */

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
	int				win_width;
	int				win_height;
	int				map_length;
	int				map_height;
	int				max_len;
	int				scalew;
	int				scaleh;
	double			posx; //start position of the player
	double			posy;
	double			view_dir; //start direction of player's POV in radians
	double			planex; //camera plane
	double			planey;
	double			angle;
	t_walltexture	walltexture;
	char			**map;
	int				floor;
	int				ceiling;
	mlx_image_t		*img;
}	t_data;

typedef struct s_gridpos
{
	double		x;
	double		y;
}	t_gridpos;

/* TEXTURE.C */
int32_t   	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		init_img(t_data *data);
void		ft_put_pixel_to_background(t_data *data);

/* MINIMAP.C */
void		ft_draw_square(t_data *data, int x, int y, int width);
void		ft_draw_minimap(t_data *data);

/* DRAW_WALL.C */
void		ft_draw_wall(t_data *data, double ray_length, int i);

/* MOVEMENTS.C */
void		move_frontback(t_data *data, int dir);
void		move_latteral(t_data *data, int dir);
void		rotate(t_data *data, int dir);
void		ft_hook(void *param);

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
int		ft_error(char *type, char *message);

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
int		ft_tablen(char **tab);
bool	is_not_last(t_data *data);
int		get_map(char *line, t_data *data);

/* FIND_INTERCEPT.C */
double	find_hor_intercept(t_data *data, double angle);
double	find_vert_intercept(t_data *data, double angle);

/* RAYCAST.C */
double	norm_angle(double angle);
void	raycast(t_data *data);

#endif
