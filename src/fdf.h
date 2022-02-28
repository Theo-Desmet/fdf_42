/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:26:16 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/28 11:59:54 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vertex
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_vertex;

typedef struct	s_map {
	int			**heigthmap;
	t_vertex	vertex;
	int			min;
	int			max;
	
}				t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
#endif
