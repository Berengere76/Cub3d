/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:41:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/05 12:23:13 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int _map_error(char *message)
{
	write (2, "Map error: ", 11);
	write (2, message, ft_strlen(message));
	return (1);
}

int	_is_direc(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c== 'W');
}

int	_is_valid(char c)
{
	return (c == ' ' || c == '1' || c == '0' || _is_direc(c));
}

int	_start_dir(char dir, char axis)
{
	if ((dir == 'N' && axis == 'Y') || (dir == 'E' && axis == 'X'))
		return (1);
	if ((dir == 'S' && axis == 'Y') || (dir == 'W' && axis == 'X'))
		return (-1);
	return (0);
}

int	parse_map(t_data *data, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (!_is_valid(map[i][j]))
				return (_map_error("invalid character (use 0,1,N,E,S,W)\n"));
			if (_is_direc(map[i][j]) && data->posX != -1)
				return (_map_error("more than one player start point given\n"));
			if (_is_direc(map[i][j]) && data->posX == -1)
			{
				data->posX = j * BLOCK_RES;
				data->posY = i * BLOCK_RES;
				data->dirX = _start_dir(map[i][j], 'X');
				data->dirY = _start_dir(map[i][j], 'Y');
			}
			j++;
		}
		i++;
	}
	if (data->posX == -1)
		return (_map_error("no player start point given\n"));
	return (0);
}
