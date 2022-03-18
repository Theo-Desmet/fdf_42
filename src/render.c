/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:34:40 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/18 12:38:30 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_angle(t_data *data)
{
	if (data->project == 0)
	{
		if (data->angle > 180)
			data->angle = 180;
		if (data->angle < 120)
			data->angle = 120;
	}
	if (data->project == 1)
	{
		if (data->angle < 0)
			data->angle = 0;
		if (data->angle > 180)
			data->angle = 180;
	}	
}

void	ft_isometric(t_map *map, t_data *data)
{
	int		i;
	int		x;
	int		y;
	int		z;
	double	angle;

	i = 0;
	angle = ((data->angle)% 360) * 3.14159265F / 180.0F;
	while (i < map->area)
	{
		x = map->heightmap[i][0] - (map->size / 2);
		x *= data->zoom;
		y = map->heightmap[i][1] - (map->height / 2);
		y *= data->zoom;
		z = map->heightmap[i][2] * -5;
		map->render[i][0] = cos(angle) * y - cos(angle) * x;
		map->render[i][1] = -z * cos(angle) * data->pos_z/2 + sin(angle) * x + sin(angle) * y;
		map->render[i][0] += data->win_wide / 2;
		map->render[i][1] += data->win_height / 2;
		map->render[i][0] += data->pos_x;
		map->render[i][1] += data->pos_y;
		map->render[i][2] = map->heightmap[i][3];
		i++;
	}	
}

void	ft_paralle(t_map *map, t_data *data)
{
	int		i;
	int		x;
	int		y;
	int		z;
	double	angle;

	i = 0;
	angle = ((data->angle)% 360) * 3.14159265F / 180.0F;
	while (i < map->area)
	{
		x = map->heightmap[i][0] - (map->size / 2);
		x *= data->zoom;
		y = map->heightmap[i][1] - (map->height / 2);
		y *= data->zoom;
		z = map->heightmap[i][2] * -5;
		map->render[i][0] = x + cos(angle) * y;
		map->render[i][1] = z * data->pos_z/2 + sin(angle) * y;
		map->render[i][0] += data->win_wide / 2;
		map->render[i][1] += data->win_height / 2;
		map->render[i][0] += data->pos_x;
		map->render[i][1] += data->pos_y;
		map->render[i][2] = map->heightmap[i][3];
		i++;
	}	
}
void	ft_aff_render(t_map *map, t_data *data)
{
	int			i;
	t_vertex	vertex1;

	i = 0;
	if (data->color == 1)
		ft_normalized_color(map);
	while (i < map->area - 1)
	{
		vertex1.x = map->render[i][0];
		vertex1.y = map->render[i][1];
		vertex1.color = map->render[i][2];
		if (map->render[i][0] > 0 && map->render[i][1] > 0
				&& map->render[i][0] < data->win_wide
				&& map->render[i][1] < data->win_height)
			ft_aff_render2(map, data, i, vertex1);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	ft_aff_render2(t_map *map, t_data *data, int i, t_vertex vertex1)
{
	t_vertex	vertex2;

	if (map->render[i + 1][0] > 0 && map->render[i + 1][1] > 0
		&& map->render[i + 1][0] < data->win_wide
		&& map->render[i + 1][1] < data->win_height
		&& map->size - 1 != i % map->size)
	{
		vertex2.x = map->render[i + 1][0];
		vertex2.y = map->render[i + 1][1];
		vertex2.color = map->render[i + 1][2];
		ft_draw_line(vertex1, vertex2, data);
	}
	if (i < map->size * map->height - map->size
		&& map->render[i + map->size][0] > 0
		&& map->render[i + map->size][1] > 0
		&& map->render[i + map->size][0] < data->win_wide
		&& map->render[i + map->size][1] < data->win_height)
	{
		vertex2.x = map->render[i + map->size][0];
		vertex2.y = map->render[i + map->size][1];
		vertex2.color = map->render[i + map->size][2];
		ft_draw_line(vertex1, vertex2, data);
	}
}
