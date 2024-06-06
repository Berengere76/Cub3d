/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:18:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/06 19:47:19 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

char map[6][5] = {
	{1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1},
};

int32_t    ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_draw_square(t_data *data, int x, int y, int width)
{
	int	y_buf;
	int	x_buf;
	
	y_buf = y;
	x_buf = x;
	while (x < (width + x_buf))
	{
		y = y_buf;
		while (y < (width + y_buf))
		{
			if (x < WIN_W && y < WIN_H)
				mlx_put_pixel(data->img, x, y, ft_pixel(0, 0, 0, 255));
			y++;
		}
		x++;
	}
}

void	init_img(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
}

void ft_put_pixel_to_background(t_data *data)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
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
}

void	ft_draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		j = 0;
		while(j < 5)
		{
			if (map[i][j] == 1)
				ft_draw_square(data, (j * 30) + 20, (i * 30) + 20, 29);
			j++;
		}
		i++;
	}
}
