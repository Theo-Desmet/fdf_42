/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:54:07 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/22 09:10:58 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_data *data)
{
	ft_free_map(data->map, data->map->area - 1);
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(EXIT_SUCCESS);
}

int	ft_close_error(t_data *data)
{
	free(data->map);
	free(data);
	exit(EXIT_FAILURE);
}

int	ft_free_file_ok(t_map *map, char *filename, int fd)
{
	ft_extremum_map(map);
	close(fd);
	free(filename);
	return (1);
}

int	ft_free_file_error(char *temp, char *filename, int fd)
{
	close(fd);
	free(temp);
	free(filename);
	return (0);
}

void	ft_free_map(t_map *map, int i)
{
	while (i >= 0)
	{
		free(map->heightmap[i]);
		free(map->render[i]);
		i--;
	}
	free(map->heightmap);
	free(map->render);
	free(map);
}
