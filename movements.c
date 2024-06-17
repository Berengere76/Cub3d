/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:27:34 by blebas            #+#    #+#             */
/*   Updated: 2024/06/17 12:54:43 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

// void	move_frontback(t_data *data, int dir)
// {	
// 	double	sin_a;
// 	double	cos_a;
// 	// t_gridpos	check_wall;

// 	sin_a = sin(data->view_dir) * MOVESPEED * dir;
// 	cos_a = cos(data->view_dir) * MOVESPEED * dir;
// 	// check_wall.y = data->posy - sin_a;
// 	// check_wall.x = data->posx - cos_a;
// 	// if (is_wall(data, check_wall))
// 	// 	return;
// 	data->posy -= sin_a;
// 	data->posx -= cos_a;
// 	ft_put_pixel_to_background(data);
// 	raycast(data);
// 	ft_draw_minimap(data);
// }

// void	move_lateral(t_data *data, int dir)
// {
// 	double	sin_a;
// 	double	cos_a;
// 	// t_gridpos	check_wall;

// 	sin_a = sin(data->view_dir) * MOVESPEED * dir;
// 	cos_a = cos(data->view_dir) * MOVESPEED * dir;
// 	// check_wall.y = data->posy + cos_a;
// 	// check_wall.x = data->posx + sin_a;
// 	// if (is_wall(data, check_wall))
// 	// 	return;
// 	data->posy += cos_a;
// 	data->posx += sin_a;
// 	ft_put_pixel_to_background(data);
// 	raycast(data);
// 	ft_draw_minimap(data);
// }

void	check_and_move(t_data *data, t_gridpos check_wall)
{
	if (is_wall(data, check_wall))
		return;
	data->posx = check_wall.x;
	data->posy = check_wall.y;
	ft_put_pixel_to_background(data);
	raycast(data);
	ft_draw_minimap(data);
}

void	move_left(t_data *data)
{
	t_gridpos	check_wall;

	check_wall.x = data->posx - sin(data->view_dir) * MOVESPEED;
	check_wall.y = data->posy - cos(data->view_dir) * MOVESPEED;

	return (check_and_move(data, check_wall));
}

void	move_right(t_data *data)
{
	t_gridpos	check_wall;

	check_wall.x = data->posx + sin(data->view_dir) * MOVESPEED;
	check_wall.y = data->posy + cos(data->view_dir) * MOVESPEED;

	return (check_and_move(data, check_wall));
}

void	move_front(t_data *data)
{
	t_gridpos	check_wall;

	check_wall.x = data->posx + cos(data->view_dir) * MOVESPEED;
	check_wall.y = data->posy - sin(data->view_dir) * MOVESPEED;

	return (check_and_move(data, check_wall));
}

void	move_back(t_data *data)
{
	t_gridpos	check_wall;

	check_wall.x = data->posx - cos(data->view_dir) * MOVESPEED;
	check_wall.y = data->posy + sin(data->view_dir) * MOVESPEED;

	return (check_and_move(data, check_wall));
}

void	rotate(t_data *data, int dir)
{
	data->view_dir = norm_angle(data->view_dir - (TURNSPEED * dir));
	ft_put_pixel_to_background(data);
	raycast(data);
	ft_draw_minimap(data);
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate(data, -1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate(data, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_front(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_back(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}
