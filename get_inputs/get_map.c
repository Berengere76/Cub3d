/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:30:11 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/07 11:11:44 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_not_last(t_data *data)
{
	if (data->walltexture.no_path == NULL)
		return (ft_errorfree("Input",
				"incomplete .cub file (missing NO)\n", data));
	if (data->walltexture.so_path == NULL)
		return (ft_errorfree("Input",
				"incomplete .cub file (missing SO)\n", data));
	if (data->walltexture.we_path == NULL)
		return (ft_errorfree("Input",
				"incomplete .cub file (missing WE)\n", data));
	if (data->walltexture.ea_path == NULL)
		return (ft_errorfree("Input",
				"incomplete .cub file (missing EA)\n", data));
	if (data->floor == -1)
		return (ft_errorfree("Input",
				"incomplete .cub file (missing F)\n", data));
	if (data->ceiling == -1)
		return (ft_errorfree("Input",
				"incomplete .cub file (missing C)\n", data));
	return (0);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}

char	**ft_realloc(char **tab)
{
	int		i;
	int		len;
	char	**output;

	i = 0;
	len = ft_tablen(tab);
	output = malloc(sizeof(char *) * (len + 2));
	if (!output)
		return (NULL);
	while (i < len)
	{
		output[i] = tab[i];
		i++;
	}
	output[i] = NULL;
	output[i + 1] = NULL;
	if (tab)
		free(tab);
	return (output);
}

int	get_map(char *line, t_data *data)
{
	int	i;

	data->map = ft_realloc(data->map);
	i = ft_tablen(data->map);
	(data->map)[i] = ft_strdup(line);
	if (!(data->map)[i])
		return (1);
	return (0);
}
