/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:35 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/21 12:11:30 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_extremum_map(t_map *map)
{
	int	i;

	map->max = -2147483648;
	map->min = 2147483647;
	i = 0;
	while (i < map->area)
	{
		if (map->heightmap[i][2] < map->min)
			map->min = map->heightmap[i][2];
		if (map->heightmap[i][2] > map->max)
			map->max = map->heightmap[i][2];
		i++;
	}
}

void	ft_normalized_color(t_map *map)
{
	int		i;
	t_color	vert;

	i = 0;
	vert.g = 0x66;
	if (map->min == map->max)
		map->max = 1;
	while (i < map->area)
	{
		vert.r = ((map->heightmap[i][2] - map->min) * 255)
			/ (map->max - map->min);
		vert.b = 255 - ((map->heightmap[i][2] - map->min) * 255)
			/ (map->max - map->min);
		map->render[i][2] = ((vert.r << 16) + (vert.g << 8) + vert.b);
		i++;
	}	
}

int	ft_hi_what_is_my_color(t_vertex vertex1, t_vertex vertex2)
{
	int		dist;
	t_color	v1;
	t_color	v2;

	dist = vertex2.x - vertex1.x;
	if (vertex2.y - vertex1.y > dist)
		dist = vertex2.y - vertex1.y;
	if (dist == 0)
		dist = 1;
	v1.r = (vertex1.color & 0xFF0000) >> 16;
	v1.g = (vertex1.color & 0x00FF00) >> 8;
	v1.b = vertex1.color & 0x0000FF;
	v2.r = (vertex2.color & 0xFF0000) >> 16;
	v2.g = (vertex2.color & 0x00FF00) >> 8;
	v2.b = (vertex2.color & 0x0000FF);
	v1.r = (v2.r - v1.r) / dist;
	v1.g = (v2.g - v1.g) / dist;
	v1.b = (v2.b - v1.b) / dist;
	return ((v1.r << 16) + (v1.g << 8) + v1.b);
}
