/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:27:34 by blebas            #+#    #+#             */
/*   Updated: 2024/06/18 17:11:12 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
