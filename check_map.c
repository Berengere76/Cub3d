/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:05:02 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/05 16:39:26 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO Check isspace
int	is_spc(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == 'f');
}

int	is_direc(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c== 'W');
}

int	is_valid(char c)
{
	return (c == '1' || c == '0' || is_direc(c));
}

int	check_0(char **map, int row, int col)
{
	int	nb_rows;

	nb_rows = 0;
	while (map[nb_rows])
		nb_rows++;
	if (row == 0 || col == 0 || row == nb_rows - 1)
		return (1);
	if (!is_valid(map[row - 1][col]) ||
			!is_valid(map[row + 1][col]) ||
			!is_valid(map[row][col - 1]) ||
			!is_valid(map[row][col + 1]))
		return (1);
	return (0);
}

int	map_open(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(is_valid(map[i][j]) == 1 || is_spc(map[i][j]) == 1))
				return (map_error("invalid character (use 0,1,N,E,S,W)\n"));
			if (map[i][j] == '0')
			{
				if (check_0(map, i, j))
					return (map_error("map is not closed\n"));
			}
			j++;
		}
		i++;
	}
	return (0);
}
