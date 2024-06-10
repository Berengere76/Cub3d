/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:27:34 by blebas            #+#    #+#             */
/*   Updated: 2024/06/10 19:00:20 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	move_frontback(t_data *data, int dir)
{	
	double	sin_a;
	double	cos_a;

	sin_a = sin(data->angle) * MOVESPEED * dir;
	cos_a = cos(data->angle) * MOVESPEED * dir;
	data->posy += sin_a;
	data->posx += cos_a;
}

void	move_latteral(t_data *data, int dir)
{
	double	sin_a;
	double	cos_a;

	sin_a = sin(data->angle) * MOVESPEED * dir;
	cos_a = cos(data->angle) * MOVESPEED * dir;
	data->posy += cos_a;
	data->posx += sin_a;
}
void	rotate(t_data *data, int dir)
{
	data->angle += 0.05 * dir;
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_frontback(data, 1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_frontback(data, -1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_latteral(data, -1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_latteral(data, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate(data, -1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate(data, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_put_pixel_to_background(data);
	ft_draw_minimap(data);
}
