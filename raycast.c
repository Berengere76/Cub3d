/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:44 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/11 18:13:06 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shortest_ray(t_data *data)
{
	double		i;
	double	hor;
	double	vert;

	i = data->dir - (FOV_RAD / 2);
	while (i < data->dir + (FOV_RAD / 2))
	{
		hor = find_hor_intercept(data, i);
		vert = find_vert_intercept(data, i);
		// call function to calculate wall height based on distance using th esmallest one
		// if (hor <= vert)
		// 	wall_height(hor);
		// else
		// 	wall_height(vert);
		i += FOV_RAD / WIN_W;
	}

	return;
}

// SEE doc - change method to calculate wall distance 