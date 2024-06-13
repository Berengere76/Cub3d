/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:44 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/13 13:17:10 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	norm_angle(double angle)
{
	if (angle > M_PI * 2)
		angle -=  M_PI * 2;
	return (angle);
}

double	ray_len(t_data *data, double ray_angle)
{
		double	hor;
		double	vert;

		hor = find_hor_intercept(data, ray_angle);
		vert = find_vert_intercept(data, ray_angle);
		if (hor <= vert)
			return (hor * cos(fabs(data->dir - ray_angle)));
		return (vert * cos(fabs(data->dir - ray_angle)));
}

void	raycast(t_data *data)
{
	double	ray_angle;
	int		i;
	double	ray_length;

	////////TODO delete this once intercepts are corrected
	double	hor;
	double	vert;
	hor = find_hor_intercept(data, data->dir + M_PI/4);
	vert = find_vert_intercept(data, data->dir + M_PI/4);
	printf("hor %f vert %f\n", hor, vert);
	ray_length = 0;
	//////////////

	ray_angle = data->dir - (FOV_RAD / 2);
	i = 0;
	// while (i < WIN_W)
	// {
	// 	norm_angle(ray_angle);
	// 	if (i == 0)
	// 		i += 0.00001;
	// 	ray_length = ray_len(data, ray_angle);
	// 	// call function to calculate wall height based on distance using the smallest one
	// 	ray_angle += FOV_RAD / WIN_W;
	// 	i++;
	// }

	return;
}
