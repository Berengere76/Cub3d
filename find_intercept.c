/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:08:28 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/12 12:34:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define OFFSET 1 //TODO - KEEP?

//axis == 0 for horzontal, 1 for vertical
bool	is_wall(t_data *data, t_gridpos intercept)
{
	if (intercept.x > (data->map_length * BLOCK_RES)
		|| intercept.x < 0 || intercept.y < 0
		|| intercept.y > (data->map_height * BLOCK_RES)
		|| isnan(intercept.x) || isnan(intercept.y))
	{
		// printf("OFFMAP\n");
		return (1);
	}
	printf("int y %f, int x %f\n", intercept.y, intercept.x);
	if (data->map[(int)(intercept.y / BLOCK_RES)][(int)(intercept.x / BLOCK_RES)] == '1')
	{
		// printf("WALL: %d %d\n", (intercept.y / BLOCK_RES), (intercept.x / BLOCK_RES));
		return (1);
	}
	return (0);
}

double find_hor_intercept(t_data *data, double angle)
{
	t_gridpos	hor_int;
	double		vector_len;

	//First intercept
	if (angle < M_PI)
		hor_int.y = (int)(data->posy / BLOCK_RES) * BLOCK_RES - OFFSET;
	else//if vector points downwards then just need to add an extra grid size
		hor_int.y = (int)(data->posy / BLOCK_RES) * BLOCK_RES + BLOCK_RES;
	hor_int.x = data->posx - sqrt(pow((fabs(data->posy - hor_int.y) * sin(angle)), 2) - pow(fabs(data->posy - hor_int.y), 2));
	// hor_int.x = data->posx + ((data->posy - hor_int.y) * tan(angle));
	vector_len = 0;

	while (!is_wall(data, hor_int))
	{
		printf("-pos %f | %f	int %f | %f\n", data->posx, data->posy, hor_int.x, hor_int.y);
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
	if (isnan(hor_int.x) || isnan(hor_int.y))
		vector_len = (data->map_height + data->map_length) * BLOCK_RES;
	else
		vector_len = sqrt(pow(fabs(data->posx - hor_int.x), 2) + pow(fabs(data->posy - hor_int.y), 2));
	printf("%f\n", vector_len);
	return (vector_len);
}

double find_vert_intercept(t_data *data, const double angle)
{
	t_gridpos	vert_int;
	double		vector_len;
	
	//First intercept
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		vert_int.x = ((int)(data->posx / BLOCK_RES) * BLOCK_RES) - OFFSET;
	else
		vert_int.x = ((int)(data->posx / BLOCK_RES) * BLOCK_RES) + BLOCK_RES;
	vert_int.y = data->posy - sqrt(pow((fabs(data->posx - vert_int.x) * sin(angle)), 2) - pow(fabs(data->posx - vert_int.x), 2));
	// vert_int.y = data->posy + ((data->posx - vert_int.x) * tan(angle));

	vector_len = 0;
	//repeat until wall or out of map
	printf("vpos %f | %f	int %f | %f\n", data->posx, data->posy, vert_int.x, vert_int.y);
	while (!is_wall(data, vert_int))
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
	if (isnan(vert_int.x) || isnan(vert_int.y))
		vector_len = (data->map_height + data->map_length) * BLOCK_RES;
	vector_len = sqrt(pow(fabs(data->posx - vert_int.x), 2) + pow(fabs(data->posy - vert_int.y), 2));
	return (vector_len);
}

//TODO get rid of all tans? east and west don't work
