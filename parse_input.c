/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:57:04 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/06 10:42:41 by kcouchma         ###   ########.fr       */
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
	while (j > 0) // check 
	{
		if (argv[i] != cub[j])
			return (1);
		j--;
		i--;
	}
	return (0);
}

//open input file
int	open_cub(char *argv)
{
	int	fd;

	if (check_cub(argv))
		return (ft_error("Input", "invalid file extension (need \".cub\""));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_error("Input", "failed to open input file"));
	return (0);
}