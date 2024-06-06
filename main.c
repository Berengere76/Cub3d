/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/06 19:06:27 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

int	data_init(t_data *data, char **map)
{
	data->width = WIN_W;
	data->height = WIN_H;
	data->posX = -1;
	if (parse_map(data, map))
		return (1);
	data->planeX = 0;
	data->planeY = 0.6;
	return (0);
}

//TODO - for later to malloc the map
// char** make_area(char** zone, t_point size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

int	main(void)
{
	// int	bpp;
	// int	size_line;
	// int	endian;
	
	// (void)argc;
	t_data	data;
	// static char *map[] = 
	// // {
	// // 	"11111",
	// // 	"10001",
	// // 	"10N01",
	// // 	"11111",
	// // };
	// {
	// 	"   11111111111111111",
	// 	"   10000000000000001",
	// 	"11110111111111111111",
	// 	"11110111111111111111",
	// 	"10000000000000000001",
	// 	"10000000000011000001",
	// 	"10000000000000000001",
	// 	"1000000N000000000001",
	// 	"11111111110011111111",
	// 	"11100000000000001   ",
	// 	"10000000000000011   ",
	// 	"11011110000111001   ",
	// 	"1111  111111 1111111"
	// }; //position 0,0 on top left

	//TODO parse inputs (must be between 0 and 255)
	// data.ceiling.R = 0;
	// data.ceiling.G = 0;
	// data.ceiling.B = 0;
	// data.floor.R = 255;
	// data.floor.G = 255;
	// data.floor.B = 255;

	//colour screen background here https://github.com/keuhdall/images_example
	// if (argc != 2)
	// 	return (ft_error("Input", "wrong number of input arguments"));
	// if (open_cub(argv[1]))
	// 	return (1);

	// if (map_open(map))
	// 	return (1);
	// if (data_init(&data, map))
	// 	return (1);
	data.mlx = mlx_init(WIN_W, WIN_H, "Hello world!", false);
	init_img(&data);
	ft_put_pixel_to_background(&data);
	ft_draw_minimap(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
