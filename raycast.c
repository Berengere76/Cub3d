/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:44 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/14 15:04:38 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	norm_angle(double angle)
{
	if (angle == 0)
		angle = 0.000001;
	if (angle > (M_PI * 2))
		angle -= M_PI * 2;
	else if (angle < 0)
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
	int		i;
	double	ray_angle;
	double	ray_length;

	i = 0;
	ray_angle = data->view_dir - (FOV_RAD / 2);
	while (i < WIN_W)
	{
		norm_angle(ray_angle);
		ray_length = ray_len(data, ray_angle);
		ft_draw_wall(data, ray_length, i);
		ray_angle += FOV_RAD / WIN_W;
		i++;
	}
	return ;
}
