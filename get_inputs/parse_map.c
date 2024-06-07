/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:41:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/07 13:38:36 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	_start_dir(char dir, char axis)
{
	if ((dir == 'N' && axis == 'Y') || (dir == 'E' && axis == 'X'))
		return (1);
	if ((dir == 'S' && axis == 'Y') || (dir == 'W' && axis == 'X'))
		return (-1);
	return (0);
}

static void	_save_start_pos(t_data *data, size_t i, size_t j)
{
	data->posx = j * BLOCK_RES;
	data->posy = i * BLOCK_RES;
	data->dirx = _start_dir(data->map[i][j], 'X');
	data->diry = _start_dir(data->map[i][j], 'Y');
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
			if (is_direc(data->map[i][j]) && data->posx != -1)
				return (ft_errorfree("Map",
						"more than one player start point given\n", data));
			if (is_direc(data->map[i][j]) && data->posx == -1)
				_save_start_pos(data, i, j);
			j++;
		}
		i++;
	}
	if (data->posx == -1)
		return (ft_errorfree("Map", "no player start point given\n", data));
	return (0);
}
