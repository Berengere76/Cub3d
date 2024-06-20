/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:41:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/20 11:41:48 by kcouchma         ###   ########.fr       */
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

static
void	*_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_size > new_size)
		old_size = new_size;
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

int	parse_map(t_data *data)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	while (i < (size_t)data->map_height)
	{
		data->map[i] = _realloc(data->map[i], ft_strlen(data->map[i]) + 1, data->map_length + 1);
		// if (data->map[i] == NULL)
		// 	// ALED
		ptr = ft_strchr(data->map[i], '\0');
		j = ptr - data->map[i];
		while (j <= (size_t)data->map_length)
			data->map[i][j++] = ' ';
		data->map[i][data->map_length] = '\0';
		++i;
	}
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
