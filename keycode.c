/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:38:41 by alixavezou        #+#    #+#             */
/*   Updated: 2022/11/06 20:08:29 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "ft_printf/ft_printf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	return (0);
	if (keycode == GO_RIGHT && data->x + 1 != '1')
	{
		ft_get_player_position(data);//on recup la position du player
		data->x++;//on le fait avancer d'une case
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_player, 32 * data->x, 32 * data->y);//puis on affiche la nouvelle map
	}//il faut redessiner la nv map avec la new position dun player
}
