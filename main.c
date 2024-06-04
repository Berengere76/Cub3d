/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/04 14:29:00 by kcouchma         ###   ########.fr       */
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
	static char *map[] = 
	{
		"   11111111111111111",
		"   10000000000000001",
		"11110111111111111111",
		"11110111111111111111",
		"10000000000000000001",
		"10000000000011000001",
		"10000000000000000001",
		"1000000000000N000001",
		"11111111110011111111",
		"11100000000000001   ",
		"10000000000000011   ",
		"11011110000111001   ",
		"1111  111111 1111111"
	};

	data.width = WIN_W;
	data.height = WIN_H;
	data.mlx = mlx_init(WIN_W, WIN_H, "Hello world!", false);
	ft_image(&data);
	if (mlx_image_to_window(data.mlx, data.image.background, 0, 0) < 0)
		error();
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
