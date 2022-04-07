/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:00:04 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/21 08:37:32 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_parsing(char *str)
{
	int	i;
	int	fd;

	i = 0;
	if (!ft_strncmp(str, ".fdf", 5))
		return (0);
	while (str[i])
		i++;
	if (ft_strncmp(&str[i - 4], ".fdf", 4))
		return (0);
	str = ft_strjoin(MAP_PATH, str);
	fd = open (str, O_RDONLY);
	free(str);
	if (fd == -1)
	{	
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
