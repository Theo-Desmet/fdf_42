/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:29:11 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/18 11:54:26 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		x;

	if (argc != 2 || !ft_parsing(argv[1]))
		return (-1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (1);
	ft_init_data(data);
	argv[1] = ft_strjoin(MAP_PATH, argv[1]);
	ft_read_file(data->map, argv[1]);
	free(argv[1]);
	x = 1;
	ft_isometric(data->map, data);
	ft_aff_render(data->map, data);
	mlx_hook(data->win, 2, 1L << 0, ft_hook, data);
	mlx_hook(data->win, 17, 1L << 3, ft_close, data);
	mlx_loop(data->mlx);
}
