/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:22:59 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/22 09:09:56 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_size(t_map *map, char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == ' '))
			cnt++;
		i++;
	}
	map->size = cnt + 1;
}

void	ft_map_height(t_map *map, char *filename)
{
	int		cnt;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	cnt = 0;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		free(line);
		cnt++;
	}
	if (close(fd) < 0)
		return ;
	map->height = cnt;
}

void	ft_heightmap(t_map *map, char *temp, int y)
{
	char	**tab;
	char	**split;
	int		x;
	int		i;

	x = -1;
	i = y * map->size;
	tab = ft_split(temp, ' ');
	while (tab[++x])
	{
		split = ft_split(tab[x], ',');
		map->heightmap[i][0] = x;
		map->heightmap[i][1] = y;
		map->heightmap[i][2] = ft_atoi(split[0]);
		if (split[1])
			map->heightmap[i][3] = ft_atoi_hex(split[1]);
		else
			map->heightmap[i][3] = 0xFFFFFF;
		i++;
		free(tab[x]);
		free(split[0]);
		free(split[1]);
		free(split);
	}
	free(tab);
}

void	ft_init_map(t_map *map, char *temp)
{
	int	i;

	i = 0;
	map->area = map->height * map->size;
	map->heightmap = malloc(sizeof(int *) * map->area + 1);
	if (!map->heightmap)
		return ;
	map->render = malloc(sizeof(int *) * map->area + 1);
	if (!map->render)
	{
		free(map->heightmap);
		return ;
	}
	while (i < map->area)
	{
		map->heightmap[i] = malloc(sizeof(int) * 4);
		map->render[i] = malloc(sizeof(int) * 3);
		if (!(map->render[i]) || !(map->heightmap[i]))
			return (ft_free_map(map, i));
		i++;
	}
}

int	ft_read_file(t_map *map, char *filename)
{
	char	*temp;
	int		fd;
	int		y;

	y = 0;
	ft_map_height(map, filename);
	fd = open(filename, O_RDONLY);
	temp = ft_get_next_line(fd);
	if (!temp)
		return (ft_free_file_error(temp, filename, fd));
	ft_map_size(map, temp);
	ft_init_map(map, temp);
	if (!map->heightmap || !map->render)
		return (ft_free_file_error(temp, filename, fd));
	while (1)
	{
		if (!temp)
			return (ft_free_file_ok(map, filename, fd));
		ft_heightmap(map, temp, y);
		y++;
		free(temp);
		temp = ft_get_next_line(fd);
	}
}
