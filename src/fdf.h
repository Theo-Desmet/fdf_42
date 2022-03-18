/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:26:16 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/18 13:14:50 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "define.h"
# include <math.h>

typedef struct s_vertex{
	int	x;
	int	y;
	unsigned long	color;
}				t_vertex;

typedef struct s_color{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_map{
	int			**heightmap;
	int			**render;
	int			min;
	int			max;
	int			size;
	int			height;	
	int			area;
}				t_map;

typedef struct s_data{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	t_map		*map;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
	int		zoom;
	int		angle;
	int		color;
	int		win_height;
	int		win_wide;
	int		pos_x;
	int		pos_y;
	int		pos_z;
	int		project;
}				t_data;

void	ft_map_size(t_map *map, char *str);
void	ft_check_angle(t_data *data);
void	ft_map_height(t_map *map, char *filename);
void	ft_heightmap(t_map *map, char *temp, int y);
void	ft_read_file(t_map *map, char *filename);
void	ft_aff_render(t_map *map, t_data *data);
void	ft_aff_render2(t_map *map, t_data *data, int i, t_vertex vertex1);
void	ft_isometric(t_map *map, t_data *data);
void	ft_paralle(t_map *map, t_data *data);
void	ft_horizontal_gradiant(t_vertex vertex1, t_vertex vertex2, t_data *data);
void	ft_vertical_gradiant(t_vertex vertex1, t_vertex vertex2, t_data *data);
void	ft_draw_line(t_vertex vertex1, t_vertex vertex2, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_normalized_color(t_map *map);
int	ft_hi_what_is_my_color(t_vertex vertex1, t_vertex vertex2);
void	ft_free_map(t_map *map);
void	ft_init_data(t_data *data);
void	ft_clear_win(t_data *data);
void	ft_hook(int keycode, t_data *data);
void	ft_hook_move(int keycode, t_data *data);
int	ft_hook_project(int keycode, t_data *data);
int	ft_close(t_data *data);
int	ft_parsing(char *str);

#endif
