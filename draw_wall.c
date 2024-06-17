/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:46:18 by blebas            #+#    #+#             */
/*   Updated: 2024/06/17 17:04:53 by blebas           ###   ########.fr       */
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

mlx_texture_t	*get_texture_side(t_data *data, t_drawwall drawwall)
{
	mlx_texture_t	*texture_wall;
	
	if (drawwall.walldirection == 'N')
		texture_wall = data->walltexture.no_walltexture;
	if (drawwall.walldirection == 'S')
		texture_wall = data->walltexture.so_walltexture;
	if (drawwall.walldirection == 'W')
		texture_wall = data->walltexture.ea_walltexture;
	if (drawwall.walldirection == 'E')
		texture_wall = data->walltexture.we_walltexture;
	return(texture_wall);
}

void	ft_draw_wall(t_data *data, t_drawwall drawwall, int i)
{
	uint32_t		color;
	double			proj_height;
	int				start;
	double			tex_x;
	double			tex_y;
	double			scale;
	mlx_texture_t	*texture;
	
	proj_height = (DIS_PROJ * BLOCK_RES) / drawwall.raylength;
	// if (proj_height > WIN_H)
	// 	proj_height = WIN_H;
	if (proj_height < WIN_H)
	{
		tex_x = 0;
		tex_y = 0;
	}
	else //(proj_height > WIN_H)
	{
		tex_x = ((proj_height - WIN_H) / 2) * (BLOCK_RES / proj_height);
		tex_y = ((proj_height - WIN_H) / 2) * (BLOCK_RES / proj_height);
		// ((proj_height - WIN_H) / 2) * (BLOCK_RES / proj_height);
	}
	printf("%f | %f\n", proj_height, tex_y);
	start = (WIN_H / 2) - (proj_height / 2);
	if (start < 0)
		start = 0;
	if (drawwall.walldirection == 'N' || drawwall.walldirection == 'S')
		tex_x = (int)drawwall.intercept.x % BLOCK_RES;
	if (drawwall.walldirection == 'E' || drawwall.walldirection == 'W')
		tex_y = (int)drawwall.intercept.y % BLOCK_RES;
	scale = BLOCK_RES / proj_height;
	// printf("proj height:%f | tex_x: %f | tex_y: %f\n", proj_height, tex_x, tex_y);
	while (proj_height > 0 && start < WIN_H)
	{
		texture = get_texture_side(data, drawwall);
		color = get_texture_color(texture, tex_x, tex_y);
		if (drawwall.walldirection == 'N' || drawwall.walldirection == 'S')
		{
			color = get_texture_color(texture, tex_x, tex_y);
			tex_y += scale;
		}
		if (drawwall.walldirection == 'E' || drawwall.walldirection == 'W')
		{
			color = get_texture_color(texture, tex_y, tex_x);
			tex_x += scale;
		}
		mlx_put_pixel(data->img, i, start, color);
		start++;
		proj_height -= 1;
	}
}
