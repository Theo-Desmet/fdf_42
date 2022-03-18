/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:01:40 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/18 10:16:53 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_horizontal_gradiant(t_vertex vertex1, t_vertex vertex2, t_data *data)
{
	int	delta[2];
	int	slope;
	int	path_y;

	delta[0] = vertex2.x - vertex1.x;
	delta[1] = vertex2.y - vertex1.y;
	path_y = 1;
	if (delta[1] < 0)
	{
		delta[1] *= -1;
		path_y = -1;
	}
	slope = 2 * delta[1] - delta[0];
	while (vertex1.x < vertex2.x)
	{
		vertex1.x += 1;
		if (slope < 0)
			slope += 2 * delta[1];
		else
		{
			vertex1.y += path_y;
			slope += 2 * (delta[1] - delta[0]);
		}
		ft_hi_what_is_my_color(vertex1, vertex2);
		my_mlx_pixel_put(data, vertex1.x, vertex1.y, vertex1.color);
	}
}

void	ft_vertical_gradiant(t_vertex vertex1, t_vertex vertex2, t_data *data)
{
	int	delta[2];
	int	slope;
	int	path_x;

	delta[0] = vertex2.x - vertex1.x;
	delta[1] = vertex2.y - vertex1.y;
	path_x = 1;
	if (delta[0] < 0)
	{
		delta[0] *= -1;
		path_x = -1;
	}
	slope = 2 * delta[0] - delta[1];
	while (vertex1.y < vertex2.y)
	{
		vertex1.y += 1;
		if (slope < 0)
			slope += 2 * delta[0];
		else
		{
			vertex1.x += path_x;
			slope += 2 * (delta[0] - delta[1]);
		}
		vertex1.color += ft_hi_what_is_my_color(vertex1, vertex2);
		my_mlx_pixel_put(data, vertex1.x, vertex1.y, vertex1.color);
	}
}

void	ft_draw_line(t_vertex vertex1, t_vertex vertex2, t_data *data)
{
	if (abs(vertex2.x - vertex1.x) > abs(vertex2.y - vertex1.y))
	{
		if (vertex1.x < vertex2.x)
			ft_horizontal_gradiant(vertex1, vertex2, data);
		else
			ft_horizontal_gradiant(vertex2, vertex1, data);
	}
	else
	{
		if (vertex1.y < vertex2.y)
			ft_vertical_gradiant(vertex1, vertex2, data);
		else
			ft_vertical_gradiant(vertex2, vertex1, data);
	}
}
