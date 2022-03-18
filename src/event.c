/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:58:31 by tdesmet           #+#    #+#             */
/*   Updated: 2022/03/18 13:29:02 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_close(data);
	else if (keycode == KEY_W_LOW || keycode == KEY_W_UPP)
	{
		data->angle++;
		ft_check_angle(data);
	}
	else if (keycode == KEY_S_LOW || keycode == KEY_S_UPP)
	{
		data->angle--;
		ft_check_angle(data);
	}
	else if (data->color == 0 && (keycode == KEY_A_UPP || keycode == KEY_A_LOW))
		data->color = 1;
	else if (data->color == 1 && (keycode == KEY_A_UPP || keycode == KEY_A_LOW))
		data->color = 0;
	ft_hook_move(keycode, data);
}

void	ft_hook_move(int keycode, t_data *data)
{
	if (data->pos_y > -1 * data->win_height && keycode == KEY_UP)
		data->pos_y -= data->win_height / 50;
	else if (data->pos_y < data->win_height && keycode == KEY_DOWN)
		data->pos_y += data->win_height / 50;
	else if (data->pos_x > -1 * data->win_wide && keycode == KEY_LEFT)
		data->pos_x -= data->win_wide / 50;
	else if (data->pos_x < data->win_wide && keycode == KEY_RIGHT)
		data->pos_x += data->win_wide / 50;
	else if (data->pos_z > 0.1 && (keycode == KEY_Q_UPP || keycode == KEY_Q_LOW))
		data->pos_z -= 1;
	else if (data->pos_z < 10 && (keycode == KEY_E_UPP || keycode == KEY_E_LOW))
		data->pos_z += 1;
	else if (data->zoom > 0 && (keycode == KEY_R_LOW || keycode == KEY_R_UPP))
		data->zoom -= data->zoom / 5;
	else if (keycode == KEY_F_LOW || keycode == KEY_F_UPP)
		data->zoom += data->zoom / 5 + 1;
	ft_hook_project(keycode, data);
}
int	ft_hook_project(int keycode, t_data *data)
{
	if (keycode == KEY_D_LOW || keycode == KEY_D_UPP)
	{
		data->project++;
		if (data->project > 1)
			data->project = 0;
		if (data->project == 0)
			data->angle = 150;
		if (data->project == 1)
			data->angle = 90;
	}
	ft_clear_win(data);
	if (data->project == 0)
		ft_isometric(data->map, data);
	else if (data->project == 1)
		ft_paralle(data->map, data);
	ft_aff_render(data->map, data);
	return (0);
}
