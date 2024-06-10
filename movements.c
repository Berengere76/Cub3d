/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:27:34 by blebas            #+#    #+#             */
/*   Updated: 2024/06/10 16:24:10 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

void	move_up(t_data *data)
{	
	data->posy += sin(data->angle) * MOVESPEED;
	data->posx += cos(data->angle) * MOVESPEED;
	ft_put_pixel_to_background(data);
	ft_draw_minimap(data);	
}

void	move_down(t_data *data)
{
	data->posy -= sin(data->angle) * MOVESPEED;
	data->posx -= cos(data->angle) * MOVESPEED;
	ft_put_pixel_to_background(data);
	ft_draw_minimap(data);	
}

void	move_left(t_data *data)
{
	data->posy += sin(data->angle + 90) * MOVESPEED;
	data->posx -= cos(data->angle + 90) * MOVESPEED;
	ft_put_pixel_to_background(data);
	ft_draw_minimap(data);	
}

void	move_right(t_data *data)
{
	data->posy -= sin(data->angle) * MOVESPEED;
	data->posx += cos(data->angle) * MOVESPEED;
	ft_put_pixel_to_background(data);
	ft_draw_minimap(data);	
}
