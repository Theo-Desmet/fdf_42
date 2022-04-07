/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:29:11 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/21 09:59:19 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || !ft_parsing(argv[1]))
		return (-1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (1);
	argv[1] = ft_strjoin(MAP_PATH, argv[1]);
	if (!ft_read_file(data->map, argv[1]))
		ft_close_error(data);
	ft_init_data(data);
	ft_isometric(data->map, data);
	ft_aff_render(data->map, data);
	mlx_hook(data->win, 2, 1L << 0, ft_hook, data);
	mlx_hook(data->win, 17, 1L << 3, ft_close, data);
	mlx_loop(data->mlx);
}
