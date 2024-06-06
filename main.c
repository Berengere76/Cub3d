/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/06 18:27:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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

int	main(int argc, char **argv)
{
	t_data	data;
	static char *map[] = 
	// {
	// 	"11111",
	// 	"10001",
	// 	"10N01",
	// 	"11111",
	// };
	{
		"   11111111111111111",
		"   10000000000000001",
		"11110111111111111111",
		"11110111111111111111",
		"10000000000000000001",
		"10000000000011000001",
		"10000000000000000001",
		"1000000N000000000001",
		"11111111110011111111",
		"11100000000000001   ",
		"10000000000000011   ",
		"11011110000111001   ",
		"1111  111111 1111111"
	}; //position 0,0 on top left

	//TODO parse input colours (must be between 0 and 255)


	//TODO INIT THIS
	data.walltexture.NO_path = NULL;
	data.walltexture.SO_path = NULL;
	data.walltexture.WE_path = NULL;
	data.walltexture.EA_path = NULL;
	data.map = NULL;

	data.ceiling = -1;
	data.floor = -1;

	
	//colour screen background here https://github.com/keuhdall/images_example
	if (argc != 2)
		return (ft_errorfree("Input", "wrong number of input arguments", &data));
	if (open_cub(argv[1], &data))
		return (1);
	
	if (map_open(map, &data))
		return (1);
	if (data_init(&data, map))
		return (1);
	printf("NO_path: %s\n", data.walltexture.NO_path);
	printf("SO_path: %s\n", data.walltexture.SO_path);
	printf("WE_path: %s\n", data.walltexture.WE_path);
	printf("EA_path: %s\n", data.walltexture.EA_path);
	printf("F colour (14827520): %d\n", data.floor);
	printf("C colour (14868480): %d\n", data.ceiling);


	// data.mlx = mlx_init(WIN_W, WIN_H, "Hello world!", false);
	// ft_image(&data);
	// if (mlx_image_to_window(data.mlx, data.image.background, 0, 0) < 0)
	// 	error();
	// mlx_loop(data.mlx);
	// mlx_terminate(data.mlx);
	ft_free(&data);
	return (0);
}
