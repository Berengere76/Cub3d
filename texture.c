/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:18:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/06 17:05:01 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

int32_t    ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_draw_square(t_data *data, int x, int y, int width)
{
	while (x < width)
	{
		y = 0;
		while (y < width)
		{
			mlx_put_pixel(data->img, x, y, ft_pixel(0, 0, 0, 255));
			y++;
		}
		x++;
	}
}

void ft_put_pixel_to_background(t_data *data)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			if (y < WIN_H / 2)
				mlx_put_pixel(data->img, x, y, ft_pixel(51, 217, 129, 255 - y));
			else
				mlx_put_pixel(data->img, x, y, ft_pixel(26, 32, 28, 255));
			y++;
		}
		x++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
