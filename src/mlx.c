/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:56:03 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/22 08:36:09 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win_wide = 1920;
	data->win_height = 1080;
	data->zoom = 50;
	data->angle = 150;
	data->project = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->pos_z = 10;
	data->color = 1;
	data->win = mlx_new_window(data->mlx, data->win_wide,
			data->win_height, "fdf");
	data->img = mlx_new_image(data->mlx, data->win_wide, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	ft_clear_win(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_wide)
		{
			my_mlx_pixel_put(data, x, y, 0);
			x++;
		}
		y++;
	}
}
