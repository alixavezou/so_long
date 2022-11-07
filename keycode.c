/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:38:41 by alixavezou        #+#    #+#             */
/*   Updated: 2022/11/07 22:00:47 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "ft_printf/ft_printf.h"

int	key_hook(int keycode, t_data *data)
{
	ft_get_player_position(data); //on recup la position du player
	if (keycode == ESC)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (keycode == GO_RIGHT && data->map[data->y][data->x + 1] != '1')
	{
		data->map[data->y][data->x++] = 'P'; //on fait bouger le player
		data->map[data->y][data->x] = 'P'; //on lui assigne P à sa nouvelle position
		data->map[data->y][data->x - 1] = '0'; //on remplace la case d'avant par un espace vide
		ft_place_xpm(data);
	}
	if (keycode == GO_LEFT && data->map[data->y][data->x - 1] != '1')
	{
		data->map[data->y][data->x--] = 'P';
		data->map[data->y][data->x] = 'P';
		data->map[data->y][data->x + 1] = '0';
		ft_place_xpm(data);
	}
	if (keycode == GO_DOWN && data->map[data->y + 1][data->x] != '1')
	{
		data->map[data->y++][data->x] = 'P';
		data->map[data->y][data->x] = 'P';
		data->map[data->y - 1][data->x] = '0';
		ft_place_xpm(data);
	}
	if (keycode == GO_UP && data->map[data->y - 1][data->x] != '1')
	{
		data->map[data->y--][data->x] = 'P';
		data->map[data->y][data->x] = 'P';
		data->map[data->y + 1][data->x] = '0';
		ft_place_xpm(data);
	}
	return (0);
}
