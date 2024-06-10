/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:52:06 by blebas            #+#    #+#             */
/*   Updated: 2024/06/10 14:24:55 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

//added a functionality to avoid the norm limitation of 4 variables -
//if you want to draw a square, set size to the height/width you want.
//if size == 0 then it will take the height and width from data->scalew/h
//to draw minimap square sizes
void	ft_draw_square(t_data *data, int x, int y, int size)
{
	int	y_buf;
	int	x_buf;
	int	width;
	int	height;

	y_buf = y;
	x_buf = x;
	width = data->scalew;
	height = data->scaleh;
	if (size > 0)
	{
		width = size;
		height = size;
	}
	while (x < (width + x_buf))
	{
		y = y_buf;
		while (y < (height + y_buf))
		{
			if (x < WIN_W && y < WIN_H)
				mlx_put_pixel(data->img, x, y, ft_pixel(0, 0, 0, 255));
			y++;
		}
		x++;
	}
}

void	ft_draw_square_red(t_data *data, int x, int y, int size)
{
	int	y_buf;
	int	x_buf;
	int	width;
	int	height;

	y_buf = y;
	x_buf = x;
	width = data->scalew;
	height = data->scaleh;
	if (size > 0)
	{
		width = size;
		height = size;
	}
	while (x < (width + x_buf))
	{
		y = y_buf;
		while (y < (height + y_buf))
		{
			if (x < WIN_W && y < WIN_H)
				mlx_put_pixel(data->img, x, y, ft_pixel(255, 0, 0, 255));
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
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				ft_draw_square(data, (j * data->scalew) + 20, (i * data->scaleh) + 20, 0);
			j++;
		}
		i++;
	}
	ft_draw_square_red(data, (((data->posx - BLOCK_RES / 2) / BLOCK_RES) * data->scalew) + 20, (((data->posy - BLOCK_RES / 2) / BLOCK_RES) * data->scaleh) + 20, 0);
}
