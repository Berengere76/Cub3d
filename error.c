/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:26:57 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/06 14:40:04 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_table(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void ft_free(t_data *data)
{
	if (data->walltexture.NO_path)
		free(data->walltexture.NO_path);
	if (data->walltexture.SO_path)
		free(data->walltexture.SO_path);
	if (data->walltexture.WE_path)
		free(data->walltexture.WE_path);
	if (data->walltexture.EA_path)
		free(data->walltexture.EA_path);
	free_table(data->map);
}

int ft_errorfree(char *type, char *message, t_data *data)
{
	write (2, "Error\n", 6);
	write (2, type, ft_strlen(type));
	write (2, " error: ", 8);
	write (2, message, ft_strlen(message));
	ft_free(data);
	return (1);
}

// int ft_error(char *type, char *message)
// {
// 	write (2, "Error\n", 6);
// 	write (2, type, ft_strlen(type));
// 	write (2, " error: ", 8);
// 	write (2, message, ft_strlen(message));
// 	return (1);
// }