/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:08:28 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/13 15:05:10 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define OFFSET 0.0000001 //TODO - KEEP?

//axis == 0 for horizontal, 1 for vertical
bool	is_wall(t_data *data, t_gridpos intercept)
{
	if (intercept.x > (data->map_length * BLOCK_RES)
			|| intercept.x < 0 || intercept.y < 0
			|| intercept.y > (data->map_height * BLOCK_RES)
			|| isnan(intercept.x) || isnan(intercept.y))
		return (1);
	if (data->map[(int)(intercept.y / BLOCK_RES)][(int)(intercept.x / BLOCK_RES)] == '1')
		return (1);
	return (0);
}

double find_hor_intercept(t_data *data, double angle)
{
	t_gridpos	hor_int;	double		vector_len;

	//First intercept
	if (angle < M_PI)
		hor_int.y = (int)(data->posy / BLOCK_RES) * BLOCK_RES - OFFSET;
	else//if vector points downwards then just need to add an extra grid size
		hor_int.y = (int)(data->posy / BLOCK_RES) * BLOCK_RES + BLOCK_RES;
	// hor_int.x = data->posx - sqrt(pow((fabs(data->posy - hor_int.y) * sin(alpha)), 2) - pow(fabs(data->posy - hor_int.y), 2));
	hor_int.x = data->posx + ((data->posy - hor_int.y) / tan(angle));
	vector_len = 0;
	// printf("hpos %f | %f	int %f | %f\n", data->posx, data->posy, hor_int.x, hor_int.y);
	while (!is_wall(data, hor_int))
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
	if (hor_int.x > (data->map_length * BLOCK_RES)
		|| hor_int.x < 0 || hor_int.y < 0
		|| hor_int.y > (data->map_height * BLOCK_RES)
		|| isnan(hor_int.x) || isnan(hor_int.y))
		vector_len = INFINITY;
	else
		vector_len = sqrt(pow(fabs(data->posx - hor_int.x), 2) + pow(fabs(data->posy - hor_int.y), 2));
	printf("%f\n", vector_len);
	return (vector_len);
}

double find_vert_intercept(t_data *data, const double angle)
{
	t_gridpos	vert_int;
	double		vector_len;

	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		vert_int.x = ((int)(data->posx / BLOCK_RES) * BLOCK_RES) - OFFSET;
	else
		vert_int.x = ((int)(data->posx / BLOCK_RES) * BLOCK_RES) + BLOCK_RES;
	vert_int.y = data->posy + ((data->posx - vert_int.x) * tan(angle));
	vector_len = 0;
	printf("vpos %f | %f	int %f | %f\n", data->posx, data->posy, vert_int.x, vert_int.y);
	while (!is_wall(data, vert_int))
	{
		if (angle > M_PI_2 && angle < 3 * M_PI_2)
		{
			vert_int.x -= BLOCK_RES;
			vert_int.y += BLOCK_RES * tan(angle);
		}
		else
		{
			vert_int.x += BLOCK_RES;
			vert_int.y -= BLOCK_RES * tan(angle);
		}
	}
	if (vert_int.x > (data->map_length * BLOCK_RES)
		|| vert_int.x < 0 || vert_int.y < 0
		|| vert_int.y > (data->map_height * BLOCK_RES)
		|| isnan(vert_int.x) || isnan(vert_int.y))
		vector_len = INFINITY;
	else
		vector_len = sqrt(pow(fabs(data->posx - vert_int.x), 2) + pow(fabs(data->posy - vert_int.y), 2));
	return (vector_len);
}

//TODO get rid of all tans? east and west don't work
