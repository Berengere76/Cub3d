/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:52:54 by blebas            #+#    #+#             */
/*   Updated: 2024/06/18 16:53:36 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx42.h"

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

void	check_and_move(t_data *data, t_gridpos check_wall)
{
	if (is_wall(data, check_wall))
		return ;
	data->posx = check_wall.x;
	data->posy = check_wall.y;
	ft_put_pixel_to_background(data);
	raycast(data);
	ft_draw_minimap(data);
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate(data, -1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate(data, 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_front(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_back(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
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
