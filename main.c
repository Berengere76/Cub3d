/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/18 16:24:27 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

// void	error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

int	data_init(t_data *data)
{
	data->walltexture.no_path = NULL;
	data->walltexture.so_path = NULL;
	data->walltexture.we_path = NULL;
	data->walltexture.ea_path = NULL;
	data->map = NULL;
	data->ceiling = -1;
	data->floor = -1;
	data->win_width = WIN_W;
	data->win_height = WIN_H;
	data->posx = -1;
	data->posy = -1;
	data->planex = 0;
	data->planey = 0.6;
	return (0);
}

void	quit_game(t_data *data)
{
	mlx_delete_texture(data->walltexture.ea_walltexture);
	mlx_delete_texture(data->walltexture.no_walltexture);
	mlx_delete_texture(data->walltexture.so_walltexture);
	mlx_delete_texture(data->walltexture.we_walltexture);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	ft_free(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_error("Input", "wrong number of input arguments\n"));
	data_init(&data);
	if (open_cub(argv[1], &data) || map_is_open(&data) || parse_map(&data)
		|| load_png(&data))
		return (1);
	data.mlx = mlx_init(WIN_W, WIN_H, "Cub3D", false);
	init_img(&data);
	ft_put_pixel_to_background(&data);
	raycast(&data);
	ft_draw_minimap(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop_hook(data.mlx, ft_hook, &data);
	mlx_loop(data.mlx);
	quit_game(&data);
	return (0);
}
