/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <blebas@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:41 by blebas            #+#    #+#             */
/*   Updated: 2024/06/04 11:31:47 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ***************** */
/*      INCLUDES     */
/* ***************** */

# include <fcntl.h>
# include "minilibx/mlx42.h"
# include "Libft/libft.h"

/* ***************** */
/*       COLORS      */
/* ***************** */

# define NC		"\e[0m"
# define YELLOW	"\e[1;33m"
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define PURPLE	"\e[1;35m"
# define CYAN	"\e[1;36m"
# define BLUE	"\e[1;34m"

/* ***************** */
/*     STRUCTURES    */
/* ***************** */

typedef struct image
{
	mlx_image_t	*background;
}		t_image;

typedef struct texture
{
	mlx_texture_t	*background_texture;
}		t_texture;

typedef struct s_data
{
	void		*mlx;
	int			width;
	int			height;
	t_image		image;
	t_texture	texture;
}	t_data;

/* TEXTURE.C */
void	ft_loadpng(t_data *data);
void	ft_texture_image(t_data *data);
void	ft_resize(t_data *data);
void	ft_image(t_data *data);

/* MAIN.C */
void	error(void);

#endif
