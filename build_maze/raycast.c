/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:44 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/18 17:46:15 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	norm_angle(double angle)
{
	if (angle == 0)
		angle = 0.000001;
	if (angle > (M_PI * 2))
		angle -= M_PI * 2;
	else if (angle < 0)
		angle += (M_PI * 2);
	return (angle);
}

bool	is_off_map(t_data *data, t_gridpos intercept)
{
	if (intercept.x > (data->map_length * BLOCK_RES)
		|| intercept.x < 0 || intercept.y < 0
		|| intercept.y >= (data->map_height * BLOCK_RES)
		|| isnan(intercept.x) || isnan(intercept.y))
		return (1);
	return (0);
}

bool	is_wall(t_data *data, t_gridpos intercept)
{
	if (data->map[(int)(intercept.y / BLOCK_RES)]
		[(int)(intercept.x / BLOCK_RES)] == '1')
		return (1);
	return (0);
}

t_drawwall	ray_len(t_data *data, double ray_angle)
{
	t_drawwall	hor;
	t_drawwall	vert;

	hor = find_hor_intercept(data, ray_angle);
	vert = find_vert_intercept(data, ray_angle);
	if (hor.raylength <= vert.raylength)
	{
		hor.raylength *= cos(fabs(data->view_dir - ray_angle));
		return (hor);
	}
	else
	{
		vert.raylength *= cos(fabs(data->view_dir - ray_angle));
		return (vert);
	}
}

void	raycast(t_data *data)
{
	int			i;
	double		ray_angle;
	t_drawwall	ray_data;

	i = 0;
	ray_angle = data->view_dir + (FOV_RAD / 2);
	while (i < WIN_W)
	{
		ray_angle = norm_angle(ray_angle);
		ray_data = ray_len(data, ray_angle);
		ft_draw_wall(data, ray_data, i);
		ray_angle -= FOV_RAD / WIN_W;
		i++;
	}
	return ;
}