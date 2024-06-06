/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:20:30 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/06 18:38:45 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_is_id(char c)
{
	return (c == 'F' || c == 'C');
}

static int	_is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int _atouc(char **temp)
{
	int	i;
	int	output;


	i = 0;
	output = 0;
	if (!(**temp >= '0' && **temp <= '9'))
		return (-1);
	while (**temp >= '0' && **temp <= '9')
	{
		if (output > 255)
			return (-1);
		output = output * 10;
		output = output + **temp - 48;
		(*temp)++;
	}
	if (output > 255)
		return (-1);
	return (output);
}

int	ctoi(char *colours)
{
	int	i;
	int	rgb;
	int	num;
	char *temp;

	i = 3;
	temp = colours;
	num = 0;
	rgb = 0;
	while (i)
	{
		if (!temp)
			return (-1);
		num = _atouc(&temp);
		if (num == -1)
			return (-1);
		rgb += num;
		rgb <<= 4;
		if (*temp == ',')
			temp++;
		i--;
	}
	rgb <<= 4;
	return (rgb);
}

int	get_colours(char *line, t_data *data)
{
	char	*temp;
	char	*colours;
	char	c;
	int		rgb;

	temp = line;
	while (is_spc(*temp))
		temp++;
	c = *temp;
	if (_is_id(*temp))
		temp++;
	while (is_spc(*temp))
		temp++;
	colours = temp;
	while (*temp && (_is_num(*temp) || *temp == ','))
		temp++;
	*temp = '\0';
	rgb = ctoi(colours);
	if (rgb == -1)
		return(ft_errorfree("Input", "invalid colour (RGB 255,255,255)\n", data));
	if (c == 'F')
		data->floor = rgb;
	else if (c == 'C')
		data->ceiling = rgb;
	return (0);
}
