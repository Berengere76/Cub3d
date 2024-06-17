/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:46:18 by blebas            #+#    #+#             */
/*   Updated: 2024/06/17 15:05:55 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	load_png(t_data *data)
{
	data->walltexture.so_walltexture = mlx_load_png(data->walltexture.so_path);
	if (!data->walltexture.so_walltexture)
		ft_errorfree("Texture", "Can't load texture", data);
	data->walltexture.ea_walltexture = mlx_load_png(data->walltexture.ea_path);
	if (!data->walltexture.ea_walltexture)
		ft_errorfree("Texture", "Can't load texture", data);
	data->walltexture.no_walltexture = mlx_load_png(data->walltexture.no_path);
	if (!data->walltexture.no_walltexture)
		ft_errorfree("Texture", "Can't load texture", data);
	data->walltexture.we_walltexture = mlx_load_png(data->walltexture.we_path);
	if (!data->walltexture.we_walltexture)
		ft_errorfree("Texture", "Can't load texture", data);
}

uint32_t get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
    uint8_t *pixel = texture->pixels + (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;
    return *(uint32_t *)pixel;
}

void	get_texture_side(t_drawwall drawwall)
{
	
}

void	ft_draw_wall(t_data *data, t_drawwall drawwall, int i)
{
	uint32_t		color;
	double			proj_height;
	int				start;
	int				tex_x;
	int				tex_y;
	mlx_texture_t	texture;
	
	tex_x = 0;
	tex_y = 0;
	proj_height = (DIS_PROJ * BLOCK_RES) / drawwall.raylength;
	if (proj_height > WIN_H)
		proj_height = WIN_H;
	start = (WIN_H / 2) - (proj_height / 2);
	while (proj_height > 0)
	{
		if (drawwall.walldirection == 'N' || drawwall.walldirection == 'S')
			tex_x = i / BLOCK_RES;
		if (drawwall.walldirection == 'E' || drawwall.walldirection == 'W')
			tex_y = start / BLOCK_RES;
		color = get_texture_color(data->walltexture.so_walltexture, tex_x, tex_y);
		mlx_put_pixel(data->img, i, start, color);
		start++;
		proj_height -= 1;
	}
}
