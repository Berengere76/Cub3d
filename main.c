/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/20 14:12:28 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	data_init(t_data *data)
{
	data->walltexture.no_path = NULL;
	data->walltexture.so_path = NULL;
	data->walltexture.we_path = NULL;
	data->walltexture.ea_path = NULL;
	data->win_width = DEFAULT_WIN_W;
	data->win_height = DEFAULT_WIN_H;
	data->map = NULL;
	data->ceiling = -1;
	data->floor = -1;
	data->pos.x = -1;
	data->pos.y = -1;
	return (0);
}

void	quit_game(t_data *data)
{
	mlx_delete_texture(data->walltexture.ea_walltexture);
	mlx_delete_texture(data->walltexture.no_walltexture);
	mlx_delete_texture(data->walltexture.so_walltexture);
	mlx_delete_texture(data->walltexture.we_walltexture);
	mlx_delete_image(data->mlx, data->img);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	ft_free(data);
}

void	_resizefunc(int32_t width, int32_t height, t_data *data)
{
	data->win_width = width;
	data->win_height = height;
	mlx_delete_image(data->mlx, data->img);
	init_img(data);
}

int	open_cub(char *argv, t_data *data)
{
	int	fd;

	if (check_cub(argv))
		return (ft_errorfree("Input",
				"invalid file extension (need \".cub\")", data));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_errorfree("Input", "failed to open input file", data));
	return (read_cub(fd, data));
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
	data.mlx = mlx_init(DEFAULT_WIN_W, DEFAULT_WIN_H, "Cub3D", true);
	init_img(&data);
	ft_put_pixel_to_background(&data);
	raycast(&data);
	ft_draw_minimap(&data);
	mlx_loop_hook(data.mlx, ft_hook, &data);
	mlx_resize_hook(data.mlx, (mlx_resizefunc)_resizefunc, &data);
	mlx_loop(data.mlx);
	quit_game(&data);
	return (0);
}
