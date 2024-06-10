/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:18:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/10 12:13:54 by blebas           ###   ########.fr       */
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

void	init_img(t_data *data)
{
	//now checks both the height and width of the map, and sets data->max_len
	//(and therefore the scaling) to whichever is longest
	int	map_length;
	int map_height;

	map_length = length_map(data);
	map_height = ft_tablen(data->map);
	if (map_length >= map_height)
		data->max_len = map_length;
	else
		data->max_len = map_height;
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	//added another scaling factor to .h so height and width can be different
	data->scalew = WIN_W / (data->max_len * (WIN_W / 125));
	data->scaleh = WIN_H / (data->max_len * (WIN_H / 125));
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
