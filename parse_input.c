/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:57:04 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/06 17:05:25 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//check for .cub extension
int	check_cub(char *argv)
{
	char *cub;
	int	i;
	int	j;

	cub = ".cub";
	i = ft_strlen(argv);
	j = ft_strlen(cub);
	if (i < j)
		return (1);
	while (j > 0)
	{
		if (argv[i] != cub[j])
			return (1);
		j--;
		i--;
	}
	return (0);
}

int	is_id(char c)
{
	return (c == 'N' || c == 'O' || c == 'S' || c == 'W' || c == 'E'
				|| c == 'A');
}

int	save_texture(char *path, char **target)
{
	if (*target)
		return (1);
	*target = path;
	return (0);
}

int	save_textures(char *path, t_data *data, char c)
{
	if (c == 'N')
		if (save_texture(path, &data->walltexture.NO_path))
			return(ft_errorfree("Input", "duplicate NO wall texture\n", data));
	if (c == 'S')
		if (save_texture(path, &data->walltexture.SO_path))
			return(ft_errorfree("Input", "duplicate SO wall texture\n", data));
	if (c == 'W')
		if (save_texture(path, &data->walltexture.WE_path))
			return(ft_errorfree("Input", "duplicate WE wall texture\n", data));
	if (c == 'E')
		if (save_texture(path, &data->walltexture.EA_path))
			return(ft_errorfree("Input", "duplicate EA wall texture\n", data));
	return (0);
}

int	get_textures(char *line, t_data *data)
{
	char *temp;
	char *path;
	char c;

	temp = line;
	while (is_spc(*temp))
		temp++;
	c = *temp;
	while (is_id(*temp))
		temp++;
	while (is_spc(*temp))
		temp++;
	path = ft_strdup(temp);
	if (!path)
		return (1);
	temp = path;
	while (*temp && !is_spc(*temp))
		temp++;
	*temp = '\0';
	if (save_textures(path, data, c))
	{
		free(path);
		return (1);
	}
	return (0);
}

int	get_colours(char *line, t_data *data)
{
	char *temp;
	char *colours;
	char c;

	temp = line;
	while (is_spc(*temp))
		temp++;
	c = *temp;
	while (is_id(*temp))
		temp++;
	while (is_spc(*temp))
		temp++;
	colours = ft_strdup(temp);
	if (!colours)
		return (1);
	temp = colours;
	while (*temp && !is_spc(*temp))
		temp++;
	*temp = '\0';
	if (c == 'F')
		data->walltexture.NO_path = colours;
	else if (c == 'C')
		data->walltexture.SO_path = colours;
	return (0);
}

int	empty_line(char *line)
{
	size_t i;

	i = 0;
	while (line[i])
	{
		if (!is_spc(line[i]))
			break;
		i++;
	}
	if (i == ft_strlen(line))
		return (1);
	return (0);
}

int	extract_data(char *line, t_data *data)
{
	char *temp;

	temp = line;
	while (is_spc(*temp))
		temp++;
	if (!strncmp(temp, "NO", 2) || !strncmp(temp, "SO", 2)
		|| !strncmp(temp, "WE", 2) || !strncmp(temp, "EA", 2))
	{
		if (get_textures(line, data))
			return (1);
	}
	else if (!strncmp(temp, "F", 1) || !strncmp(temp, "C", 1))
	{
		if (get_colours(line, data))
			return (1);
	}
	// //handle invalid input
	// else //TODO make sure the map is read only if others are ok
	// {
	// 	if (get_map(temp, data))
	// 		return (1);
	// }
	return (0);
}


int	read_cub(int fd, t_data *data)
{
	char	*line;

	while (1)
	{
		line = gnl(fd);
		if (!line)
			break;
		line[ft_strlen(line) - 1] = '\0';
		if (!empty_line(line))
		{
			if (extract_data(line, data))
			{
				free(line);
				return (1);
			}
		}
		free(line);
	}
	return (0);
}

//open input file .cub
int	open_cub(char *argv, t_data *data)
{
	int	fd;

	if (check_cub(argv))
		return (ft_errorfree("Input", "invalid file extension (need \".cub\")", data));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_errorfree("Input", "failed to open input file", data));
	return (read_cub(fd, data));
}