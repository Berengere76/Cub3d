/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/04 11:24:33 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	main(void)
{
	t_data	data;

	data.width = 600;
	data.height = 400;
	data.mlx = mlx_init(600, 400, "Hello world!", false);
	ft_image(&data);
	if (mlx_image_to_window(data.mlx, data.image.background, 0, 0) < 0)
		error();
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
