/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:08:28 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/11 14:11:49 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define OFFSET 0.0001 //TODO - KEEP?

//axis == 0 for horzontal, 1 for vertical
bool	is_wall(t_data *data, t_gridpos intercept, double angle, bool axis)
{
	if (axis == 0)
		if (!((int)intercept.x % BLOCK_RES) && (angle > M_PI_2 && angle < 3 * M_PI_2))
			intercept.x -= BLOCK_RES;
	if (axis == 1)
		if (!((int)intercept.y % BLOCK_RES) && (angle < M_PI))
			intercept.y -= BLOCK_RES;
	if (data->map[(int)(intercept.y / BLOCK_RES)][(int)(intercept.x / BLOCK_RES)] == 1)
		return (1);
	return (0);
}

bool	out_of_map(t_data *data, t_gridpos hor_int)
{
	if (hor_int.x > (data->map_length * BLOCK_RES)
		|| hor_int.x < 0 || hor_int.y < 0
		|| hor_int.y > (data->map_height * BLOCK_RES))
		return (1);
	return (0);
}

t_gridpos find_hor_intercept(t_data *data, double angle)
{
	t_gridpos hor_int;
	t_gridpos hor_max;

	// if (angle == 0)
	// 	angle += 0.0001; //TODO teeny offset to make sure we're never on 0
	
	//First intercept
	if (angle < M_PI)
		hor_int.y = (int)(data->posy / BLOCK_RES) * BLOCK_RES - OFFSET; //tiny offset here to make sure we round up to the right square to identify the wall
	else//if vector points downwards then just need to add an extra grid size
		hor_int.y = (int)(data->posy / BLOCK_RES) * BLOCK_RES + BLOCK_RES;
	hor_int.x = data->posx + ((data->posy - hor_int.y) * tan(angle));

	// printf("y_pos: %f x_pos: %f\n", data->posy, data->posx);
	//repeat until wall or out of map
	while (!out_of_map(data, hor_int) && !is_wall(data, hor_int, angle, 0))
	{
		// printf("hor_int.y: %f hor_int.x: %f\n", hor_int.y, hor_int.x);
		hor_max.x = hor_int.x;
		hor_max.y = hor_int.y;
		if (angle < M_PI)
			hor_int.y -= BLOCK_RES;
		else
			hor_int.y += BLOCK_RES;
		hor_int.x += BLOCK_RES / tan(angle);
	}
	return (hor_max);
}

t_gridpos find_vert_intercept(t_data *data, double angle)
{
	t_gridpos vert_int;
	t_gridpos vert_max;
	
	//First intercept
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		vert_int.x = (int)(data->posx / BLOCK_RES) * BLOCK_RES - OFFSET;
	else//if vector points downwards then just need to add an extra grid size
		vert_int.x = (int)(data->posx / BLOCK_RES) * BLOCK_RES + BLOCK_RES; //tiny offset here to make sure we round up to the right square to identify the wall
	vert_int.y = data->posy + ((data->posx - vert_int.x) * tan(angle));

	printf("y_pos: %f x_pos: %f\n", data->posy, data->posx);
	//repeat until wall or out of map
	while (!out_of_map(data, vert_int) && !is_wall(data, vert_int, angle, 1))
	{
		printf("vert_int.x: %f vert_int.y: %f\n", vert_int.x, vert_int.y);
		vert_max.x = vert_int.x;
		vert_max.y = vert_int.y;
		if (angle > M_PI_2 && angle < 3 * M_PI_2)
			vert_int.x -= BLOCK_RES;
		else
			vert_int.x += BLOCK_RES;
		vert_int.y += BLOCK_RES / tan(angle);
	}
	return (vert_max);
}

