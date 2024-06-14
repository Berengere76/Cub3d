/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:44 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/14 11:37:39 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	norm_angle(double angle)
{
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	else if (angle <= 0)
		angle += M_PI * 2;
	return (angle);
}

double	ray_len(t_data *data, double ray_angle)
{
	double	hor;
	double	vert;

	hor = find_hor_intercept(data, ray_angle);
	vert = find_vert_intercept(data, ray_angle);
	if (hor <= vert)
		return (hor * cos(fabs(data->view_dir - ray_angle)));
	return (vert * cos(fabs(data->view_dir - ray_angle)));
}

void	raycast(t_data *data)
{
	double	ray_angle;
	int		i;
	double	ray_length;

	ray_angle = data->view_dir - (FOV_RAD / 2);
	i = 0;
	while (i < WIN_W)
	{
		norm_angle(ray_angle);
		ray_length = ray_len(data, ray_angle);
		// call function to calculate wall height based on distance and write to image
		ray_angle += FOV_RAD / WIN_W;
		i++;
	}
	return ;
}
