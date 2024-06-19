/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:18:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/19 17:30:28 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	init_img(t_data *data)
{
	size_t	max_dimension;

	data->map_length = length_map(data);
	data->map_height = ft_tablen(data->map);
	if (data->map_length >= data->map_height)
		max_dimension = data->map_length;
	else
		max_dimension = data->map_height;
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->scalew = WIN_W / (max_dimension * (WIN_W / 125));
	data->scaleh = WIN_H / (max_dimension * (WIN_H / 125));
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
