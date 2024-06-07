/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:18:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/07 15:05:21 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	length_map(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (j > len)
				len++;
			j++;
		}
		i++;
	}
	return (len);
}

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

void	init_img(t_data *data)
{
	int	map_length;
	int map_height;

	map_length = length_map(data);
	map_height = ft_tablen(data->map);
	if (map_length >= map_height)
		data->max_len = map_length;
	else
		data->max_len = map_height;
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->scalew = WIN_W / (data->max_len * (WIN_W / 150));
	data->scaleh = WIN_H / (data->max_len * (WIN_H / 150));
}

void	ft_put_pixel_to_background(t_data *data)
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
				mlx_put_pixel(data->img, x, y, data->ceiling);
			else
				mlx_put_pixel(data->img, x, y, data->floor);
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
}

void	get_player_pos(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 2)
			{
				data->posx = x;
				data->posy = y;
			}
		}
	}
}

void	put_player_on_minimap(t_data *data, int x, int y)
{
	if (data->map[y][x] == 2)
	{
		ft_draw_square(data, x, y, 10);
	}
}
