/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:44 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/12 10:21:20 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shortest_ray(t_data *data)
{
	double		i;
	double	hor;
	double	vert;

	hor = find_hor_intercept(data, data->dir);
	vert = find_vert_intercept(data, data->dir);
	printf("hor %f vert %f\n", hor, vert);

	i = data->dir - (FOV_RAD / 2);
	// while (i < data->dir + (FOV_RAD / 2))
	// {
	// 	if (i == 0)
	// 		i += 0.00001;
	// 	hor = find_hor_intercept(data, i);
	// 	vert = find_vert_intercept(data, i);
	// 	// call function to calculate wall height based on distance using th esmallest one
	// 	// if (hor <= vert)
	// 	// 	wall_height(hor);
	// 	// else
	// 	// 	wall_height(vert);
	// 	i += FOV_RAD / WIN_W;
	// }

	return;
}
