/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:18:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/04 11:21:36 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	ft_loadpng(t_data *data)
{
	data->texture.background_texture = mlx_load_png("./assets/decor.png");
	if (!data->texture.background_texture)
		error();
}

void	ft_texture_image(t_data *data)
{
	data->image.background = mlx_texture_to_image(data->mlx,
			data->texture.background_texture);
	if (!data->image.background)
		error();
}

void	ft_resize(t_data *data)
{
	mlx_resize_image(data->image.background, data->width, data->height);
}

void	ft_image(t_data *data)
{
	ft_loadpng(data);
	ft_texture_image(data);
	ft_resize(data);
}
