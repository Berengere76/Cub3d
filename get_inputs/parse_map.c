/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:41:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/19 14:01:07 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	_start_rad(char dir)
{
	if (dir == 'E')
		return (0);
	else if (dir == 'N')
		return (M_PI_2);
	else if (dir == 'W')
		return (M_PI);
	else if (dir == 'S')
		return (3 * M_PI_2);
	return (0);
}

static void	_save_start_pos(t_data *data, size_t i, size_t j)
{
	data->pos.x = (j * BLOCK_RES) + (BLOCK_RES / 2);
	data->pos.y = (i * BLOCK_RES) + (BLOCK_RES / 2);
	data->view_dir = _start_rad(data->map[i][j]);
}

int	parse_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (j < ft_strlen(data->map[i]))
		{
			if (is_direc(data->map[i][j]) && data->pos.x != -1)
				return (ft_errorfree("Map",
						"more than one player start point given\n", data));
			if (is_direc(data->map[i][j]) && data->pos.x == -1)
				_save_start_pos(data, i, j);
			j++;
		}
		i++;
	}
	if (data->pos.x == -1)
		return (ft_errorfree("Map", "no player start point given\n", data));
	return (0);
}
