/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/07 11:33:07 by kcouchma         ###   ########.fr       */
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
	data->planex = 0;
	data->planey = 0.6;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_errorfree("Input", "wrong number of input arguments", &data));
	data_init (&data);
	if (open_cub(argv[1], &data))
		return (1);
	if (map_is_open(&data))
		return (1);
	if (parse_map(&data))
		return (1);

//PRINT INPUT VARIABLES
	printf("NO_path: %s\n", data.walltexture.no_path);
	printf("SO_path: %s\n", data.walltexture.so_path);
	printf("WE_path: %s\n", data.walltexture.we_path);
	printf("EA_path: %s\n", data.walltexture.ea_path);
	printf("F colour (14827520): %d\n", data.floor);
	printf("C colour (14868480): %d\n", data.ceiling);
	int	i = 0;
	while (data.map[i])
	{
		printf("%s\n", data.map[i]);
		i++;
	}

	// data.mlx = mlx_init(WIN_W, WIN_H, "Hello world!", false);
	// ft_image(&data);
	// if (mlx_image_to_window(data.mlx, data.image.background, 0, 0) < 0)
	// 	error();
	// mlx_loop(data.mlx);
	// mlx_terminate(data.mlx);
	ft_free(&data);
	return (0);
}
