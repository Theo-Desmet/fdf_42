/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:01:40 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/21 14:48:22 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hor_gradiant(t_vertex vertex1, t_vertex vertex2, t_data *data)
{
	int	delta[3];
	int	path_y;

	delta[0] = vertex2.x - vertex1.x;
	delta[1] = vertex2.y - vertex1.y;
	path_y = 1;
	if (delta[1] < 0)
	{
		delta[1] *= -1;
		path_y = -1;
	}
	delta[2] = 2 * delta[1] - delta[0];
	while (vertex1.x < vertex2.x)
	{
		vertex1.x += 1;
		if (delta[2] < 0)
			delta[2] += 2 * delta[1];
		else
		{
			vertex1.y += path_y;
			delta[2] += 2 * (delta[1] - delta[0]);
		}
		ft_hi_what_is_my_color(vertex1, vertex2);
		my_mlx_pixel_put(data, vertex1.x, vertex1.y, vertex1.color);
	}
}

void	ft_ver_gradiant(t_vertex vertex1, t_vertex vertex2, t_data *data)
{
	int	delta[3];
	int	path_x;

	delta[0] = vertex2.x - vertex1.x;
	delta[1] = vertex2.y - vertex1.y;
	path_x = 1;
	if (delta[0] < 0)
	{
		delta[0] *= -1;
		path_x = -1;
	}
	delta[2] = 2 * (delta[0] - delta[1]);
	while (vertex1.y < vertex2.y)
	{
		vertex1.y += 1;
		if (delta[2] < 0)
			delta[2] += 2 * delta[0];
		else
		{
			vertex1.x += path_x;
			delta[2] += 2 * (delta[0] - delta[1]);
		}
		vertex1.color += ft_hi_what_is_my_color(vertex1, vertex2);
		my_mlx_pixel_put(data, vertex1.x, vertex1.y, vertex1.color);
	}
}

/* 
if (vertex1.x > 0 && vertex1.y> 0
                                && vertex1.x < data->win_wide
                                && vertex1.y< data->win_height)
*/

void	ft_draw_line(t_vertex vertex1, t_vertex vertex2, t_data *data)
{
	if (abs(vertex2.x - vertex1.x) > abs(vertex2.y - vertex1.y))
	{
		if (vertex1.x < vertex2.x)
			ft_hor_gradiant(vertex1, vertex2, data);
		else
			ft_hor_gradiant(vertex2, vertex1, data);
	}
	else
	{
		if (vertex1.y < vertex2.y)
			ft_ver_gradiant(vertex1, vertex2, data);
		else
			ft_ver_gradiant(vertex2, vertex1, data);
	}
}
