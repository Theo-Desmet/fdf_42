/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:22:59 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/28 16:16:23 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_read_file()
{
	t_map	map;
	char	*tab;
	int	fd;
	int	i;

	fd = open("maps/test_maps/42.fdf", O_RDONLY);
	if (fd < 0)
		return ;//secu
	temp = ft_get_next_line(fd);
	while (tab)
	{
		i++;
	}
	
}

char	**ft_heigthmap(t_map map, char *temp, int y)
{
	char	*split;
	char	**tab;
	int		i;
	size_t	*line;

	tab = ft_split(temp, ' ');
	while (tab[i])
	{
		split = ft_split(tab[i]);
			
	}

}
