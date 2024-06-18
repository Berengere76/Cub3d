/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:46:18 by blebas            #+#    #+#             */
/*   Updated: 2024/06/18 13:55:08 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

bool	load_png(t_data *data)
{
	data->walltexture.so_walltexture = mlx_load_png(data->walltexture.so_path);
	if (!data->walltexture.so_walltexture)
		return (ft_errorfree("Texture", "Can't load texture (SO)\n", data));
	data->walltexture.ea_walltexture = mlx_load_png(data->walltexture.ea_path);
	if (!data->walltexture.ea_walltexture)
		return (ft_errorfree("Texture", "Can't load texture (EA)\n", data));
	data->walltexture.no_walltexture = mlx_load_png(data->walltexture.no_path);
	if (!data->walltexture.no_walltexture)
		return (ft_errorfree("Texture", "Can't load texture (NO)\n", data));
	data->walltexture.we_walltexture = mlx_load_png(data->walltexture.we_path);
	if (!data->walltexture.we_walltexture)
		return (ft_errorfree("Texture", "Can't load texture (WE)\n", data));
	return (0);
}

uint32_t get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint8_t	*pixel;
	
	pixel = texture->pixels + (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;
	return *(uint32_t *)pixel;
}

mlx_texture_t	*get_texture_side(t_data *data, t_drawwall drawwall)
{
	mlx_texture_t	*texture_wall;
	
	if (drawwall.walldirection == 'N')
		texture_wall = data->walltexture.no_walltexture;
	if (drawwall.walldirection == 'S')
		texture_wall = data->walltexture.so_walltexture;
	if (drawwall.walldirection == 'W')
		texture_wall = data->walltexture.we_walltexture;
	if (drawwall.walldirection == 'E')
		texture_wall = data->walltexture.ea_walltexture;
	return(texture_wall);
}

void	ft_draw_wall2(t_drawwall drawwall, t_gridpos *tex, double proj_height,
	mlx_texture_t *texture)
{
	double	y_stuff;

	y_stuff = 0;
	if (proj_height >= WIN_H)
		y_stuff = ((proj_height - WIN_H) / 2) * (texture->height / proj_height);
	tex->y = y_stuff;
	if (drawwall.walldirection == 'N')
		tex->x = ((int)drawwall.intercept.x % BLOCK_RES);
	if (drawwall.walldirection == 'S')
		tex->x = (BLOCK_RES - ((int)drawwall.intercept.x % BLOCK_RES));
	if (drawwall.walldirection == 'E')
		tex->x = ((int)drawwall.intercept.y % BLOCK_RES);
	if (drawwall.walldirection == 'W')
		tex->x = (BLOCK_RES - ((int)drawwall.intercept.y % BLOCK_RES));
	tex->x *= texture->width / BLOCK_RES;
}

void	ft_draw_wall(t_data *data, t_drawwall drawwall, int i)
{
	uint32_t		color;
	double			proj_height;
	int				start;
	t_gridpos		tex;
	double		scale;
	mlx_texture_t	*texture;
	
	proj_height = (DIS_PROJ * BLOCK_RES) / drawwall.raylength;
	start = (WIN_H / 2) - (proj_height / 2);
	if (start < 0)
		start = 0;
	texture = get_texture_side(data, drawwall);
	ft_draw_wall2(drawwall, &tex, proj_height, texture);
	scale = texture->height / proj_height;
	while (proj_height > 0 && start < WIN_H)
	{
		color = get_texture_color(texture, tex.x, tex.y);
		tex.y += scale;
		mlx_put_pixel(data->img, i, start, color);
		start++;
		proj_height -= 1;
	}
}
