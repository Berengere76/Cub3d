/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:08:28 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/11 18:10:36 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define OFFSET 1 //TODO - KEEP?

//axis == 0 for horzontal, 1 for vertical
bool	is_wall(t_data *data, t_gridpos intercept)
{
	if (data->map[(intercept.y / BLOCK_RES)][(intercept.x / BLOCK_RES)] == '1')
	{
		// printf("WALL: %d %d\n", (intercept.y / BLOCK_RES), (intercept.x / BLOCK_RES));
		return (1);
	}
	return (0);
}

bool	out_of_map(t_data *data, t_gridpos hor_int)
{
	if (hor_int.x > (data->map_length * BLOCK_RES)
		|| hor_int.x < 0 || hor_int.y < 0
		|| hor_int.y > (data->map_height * BLOCK_RES))
	{
		// printf("OFFMAP\n");
		return (1);
	}
	return (0);
}

double find_hor_intercept(t_data *data, double angle)
{
	t_gridpos	hor_int;
	double		vector_len;

	if (angle == 0)
		angle += 0.0001; //TODO teeny offset to make sure we're never on 0
	
	//First intercept
	if (angle < M_PI)
		hor_int.y = (data->posy / BLOCK_RES) * BLOCK_RES - OFFSET; //tiny offset here to make sure we round up to the right square to identify the wall
	else//if vector points downwards then just need to add an extra grid size
		hor_int.y = (data->posy / BLOCK_RES) * BLOCK_RES + BLOCK_RES;
	hor_int.x = data->posx + ((data->posy - hor_int.y) * tan(angle));

	printf("y_pos: %d x_pos: %d\n", data->posy, data->posx);
	//repeat until wall or out of map
	while (!out_of_map(data, hor_int) && !is_wall(data, hor_int))
	{
		if (angle < M_PI)
		{
			hor_int.y -= BLOCK_RES;
			hor_int.x += BLOCK_RES / tan(angle);
		}
		else
		{
			hor_int.y += BLOCK_RES;
			hor_int.x -= BLOCK_RES / tan(angle);
		}
	}
	vector_len = sqrt((data->posx - hor_int.x) * (data->posx - hor_int.x)
		+ (data->posy - hor_int.y) * (data->posy - hor_int.y));
	return (vector_len);
}

double find_vert_intercept(t_data *data, const double angle)
{
	t_gridpos	vert_int;
	double		vector_len;
	
	//First intercept
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		vert_int.x = ((data->posx / BLOCK_RES) * BLOCK_RES) - OFFSET;
	else
		vert_int.x = ((data->posx / BLOCK_RES) * BLOCK_RES) + BLOCK_RES;
	vert_int.y = data->posy + ((data->posx - vert_int.x) * tan(angle));

	//repeat until wall or out of map
	while (!out_of_map(data, vert_int) && !is_wall(data, vert_int))
	{
		if (angle > M_PI_2 && angle < 3 * M_PI_2)
		{
			vert_int.x -= BLOCK_RES;
			vert_int.y += BLOCK_RES / tan(angle);
		}
		else
		{
			vert_int.x += BLOCK_RES;
			vert_int.y -= BLOCK_RES / tan(angle);
		}
	}
	vector_len = sqrt((data->posx - vert_int.x) * (data->posx - vert_int.x)
		+ (data->posy - vert_int.y) * (data->posy - vert_int.y));
	return (vector_len);
}

