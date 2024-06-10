/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:08:28 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/10 17:59:42 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	is_wall(double posx, double posy)
// {

// }

double find_hor_intercept(t_data *data, double angle)
{
	double	y_int;
	double	x_int;
	
	if (angle == 0)
		angle += 0.0001; //TODO teeny offset to make sure we're never on 0
	y_int = (int)(data->posy / BLOCK_RES) * BLOCK_RES; //TODO will need to add tiny offset here
	if (angle > M_PI) //if vector points downwards then just need to add an extra grid size
		y_int += BLOCK_RES;
	x_int = data->posx - ((data->posy - y_int) * tan(angle));
	printf("y_pos: %f x_pos: %f\n", data->posy, data->posx);
	printf("y_int: %f x_int: %f\n", y_int, x_int);
	// while (!is_wall(posx, posy) || !out_of_map(posx, posy))
	// {
	// 	keep adding xa/ya until one of these is true
	// 	Xa = BLOCK_RES / tan(angle);
	// 	Ya = BLOCK_RES;
	// }
	return (0); ////TODO NOOOOOOOOOOOOOOOO
}