/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:46:18 by blebas            #+#    #+#             */
/*   Updated: 2024/06/13 17:25:39 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	ft_draw_wall(t_data *data, double ray_lenght, int i)
{
	double	proj_height;
	int		start;

	// proj_height = (DIS_PROJ * BLOCK_RES) / ray_lenght;
	proj_height = (BLOCK_RES / ray_lenght) * DIS_PROJ;
	start = (DIS_PROJ / 2) - (proj_height / 2);
	// start = 0;
	// printf("proj height : %f\n", proj_height);
	// printf("dis proj : %f\n", DIS_PROJ);
	while (start < proj_height)
	{
		// printf("start : %d\n", start);
		mlx_put_pixel(data->img, i, start, ft_pixel(255, 255, 255, 255));
		start++;
	}
}
