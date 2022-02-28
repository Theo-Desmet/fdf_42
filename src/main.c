/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:29:11 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/28 11:46:16 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


/*
void bresenham(int x1, int y1, int x2, int y2, t_data img)
{
	int	dy;
	int	dx;
	int	slope;
	int	i;

	i = 0;
	dy = 2 * (y2 - y1);
	dx = 2 * (x2 - x1);
	slope = x2 - x1;
	while(i != dx / 2) 
	{
		if (x1 < x2)
			x1++;
		else
			x2--;
		my_mlx_pixel_put(&img, x1, y1, 0xFFFFFF);
		if (slope >= 0)
		{
			y1++;
			slope -= dy;
		}
		slope += dx;
		i++;
	}
}*/

int	main(void)
{
	/*
	t_vars	vars;
	t_data	img;
	int x;

	x = 1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	bresenham(2, 2, 5, 15, img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);*/
	ft_read_file();
}
