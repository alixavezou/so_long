/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:38:41 by alixavezou        #+#    #+#             */
/*   Updated: 2022/07/22 13:54:08 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "ft_printf/ft_printf.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	return (0);
}
