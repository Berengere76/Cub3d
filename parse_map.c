/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:41:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/05 15:46:13 by kcouchma         ###   ########.fr       */
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

void	ft_fill(bool *badmap, char **map, long long row, long long col, long long nbrows)
{
	printf("row %lld | col %lld\n", row, col);
	if (row >= nbrows || row < 0 || col < 0 || (map[row][col]) == '\0')
		return;
	printf("here\n");
	if (map[row][col] == ' ' || _is_valid(map[row][col]) == 0)
	{
		printf("badmap\n");
		*badmap = 1;
	}
	if (map[row][col] == '1')
		return;
	map[row][col] = 'F';
	// printf("%c\n", map[row][col]);
	// printf("%s | %c | %lld | %lld | %lld \n", *badmap ? "true" : "false", map[row][col], row, col, nbrows);

	ft_fill(badmap, map, row + 1, col, nbrows);
	ft_fill(badmap, map, row - 1, col, nbrows);
	ft_fill(badmap, map, row, col + 1, nbrows);
	ft_fill(badmap, map, row, col - 1, nbrows);
}
	
int	flood_fill(char **map, long long row, long long col)
{
	bool badmap;
	long long nbrows;

	badmap = 0;
	// printf("%s\n", badmap ? "true" : "false");
	nbrows = 0;
	while (map[nbrows])
		nbrows++;
	ft_fill(badmap, map, row, col, nbrows);
	return (badmap);
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
				if (flood_fill(map, i, j))
					return (_map_error("invalid map\n"));
			}
			j++;
		}
		i++;
	}
	if (data->posX == -1)
		return (_map_error("no player start point given\n"));
	return (0);
}
