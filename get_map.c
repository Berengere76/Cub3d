/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:30:11 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/06 18:45:22 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO individual error messages
int	check_last(t_data *data)
{
	if (data->walltexture.NO_path == NULL ||
			data->walltexture.SO_path == NULL ||
			data->walltexture.WE_path == NULL ||
			data->walltexture.EA_path == NULL ||
			data->floor == -1 ||
			data->ceiling == -1)
		return (1);
	return (0);
}

int	get_map(char *line, t_data *data)
{
	line = NULL;
	if (check_last(data))
		return (ft_errorfree("Input", "incomplete .cub file\n", data));
	return (0);
}