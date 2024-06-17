/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:46:18 by blebas            #+#    #+#             */
/*   Updated: 2024/06/14 14:59:56 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	ft_draw_wall(t_data *data, double ray_length, int i)
{
	double	proj_height;
	int		start;

	// proj_height = (DIS_PROJ * BLOCK_RES) / ray_lenght;
	proj_height = (DIS_PROJ * BLOCK_RES) / ray_length;
	if (proj_height > WIN_H)
		proj_height = WIN_H;
	start = (WIN_H / 2) - (proj_height / 2);
	// printf("start : %d | proj height : %f\n", start, proj_height);
	// start = 0;
	// printf("proj height : %f\n", proj_height);
	// printf("dis proj : %f\n", DIS_PROJ);
	while (proj_height > 0)
	{
		mlx_put_pixel(data->img, i, start, ft_pixel(255, 255, 255, 255));
		start++;
		proj_height -= 1;
	}
}
