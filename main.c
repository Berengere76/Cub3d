/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/07 14:59:22 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	data_init(t_data *data)
{
	data->walltexture.no_path = NULL;
	data->walltexture.so_path = NULL;
	data->walltexture.we_path = NULL;
	data->walltexture.ea_path = NULL;
	data->map = NULL;
	data->ceiling = -1;
	data->floor = -1;
	data->width = WIN_W;
	data->height = WIN_H;
	data->posx = -1;
	data->posy = -1;
	data->planex = 0;
	data->planey = 0.6;
	return (0);
}

int	main(int argc, char **argv)
{

	t_data	data;
	//colour screen background here https://github.com/keuhdall/images_example
	if (argc != 2)
		return (ft_errorfree("Input", "wrong number of input arguments", &data));
	data_init(&data);
	if (open_cub(argv[1], &data) || map_is_open(&data) || parse_map(&data))
		return (1);

//PRINT INPUT VARIABLES
	printf("NO_path: %s\n", data.walltexture.no_path);
	printf("SO_path: %s\n", data.walltexture.so_path);
	printf("WE_path: %s\n", data.walltexture.we_path);
	printf("EA_path: %s\n", data.walltexture.ea_path);
	printf("F colour (14827520): %d\n", data.floor);
	printf("C colour (14868480): %d\n", data.ceiling);
	printf("start positionx: %f - %f\n", data.posx, data.posx / 64);
	printf("start positiony: %f - %f\n", data.posy, data.posy / 64);
	printf("start directionx: %f\n", data.dirx);
	printf("start directiony: %f\n", data.diry);
	int	i = 0;
	while (data.map[i])
	{
		printf("%s\n", data.map[i]);
		i++;
	}
/////////////////////////

	data.mlx = mlx_init(WIN_W, WIN_H, "Hello world!", false);
	init_img(&data);
	ft_put_pixel_to_background(&data);
	ft_draw_minimap(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
