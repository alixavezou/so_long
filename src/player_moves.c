/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:38:41 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/05 13:16:08 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	ft_get_player_position(data);
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(1);
	}
	if (keycode == GO_RIGHT || keycode == D_KEY)
		ft_move_right(data);
	if (keycode == GO_LEFT || keycode == A_KEY)
		ft_move_left(data);
	if (keycode == GO_DOWN || keycode == S_KEY)
		ft_move_down(data);
	if (keycode == GO_UP || keycode == W_KEY)
		ft_move_up(data);
	ft_printf("Number of moves: %d\n", data->compteur_of_moves);
	return (0);
}

void	ft_move_right(t_data *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		data->x++;
		if (data->map[data->y][data->x] == 'C')
			data->collected_items++;
		data->compteur_of_moves++;
		data->map[data->y][data->x] = 'P';
		if (data->y == data->exit_y && data->x - 1 == data->exit_x)
			data->map[data->y][data->x - 1] = 'E';
		else
			data->map[data->y][data->x - 1] = '0';
		ft_place_xpm(data);
		ft_handle_exit(data);
	}
}

void	ft_move_left(t_data *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		data->x--;
		if (data->map[data->y][data->x] == 'C')
			data->collected_items++;
		data->compteur_of_moves++;
		data->map[data->y][data->x] = 'P';
		if (data->y == data->exit_y && data->x + 1 == data->exit_x)
			data->map[data->y][data->x + 1] = 'E';
		else
			data->map[data->y][data->x + 1] = '0';
		ft_place_xpm(data);
		ft_handle_exit(data);
	}
}

void	ft_move_down(t_data *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		data->y++;
		if (data->map[data->y][data->x] == 'C')
			data->collected_items++;
		data->compteur_of_moves++;
		data->map[data->y][data->x] = 'P';
		if (data->y - 1 == data->exit_y && data->x == data->exit_x)
			data->map[data->y - 1][data->x] = 'E';
		else
			data->map[data->y - 1][data->x] = '0';
		ft_place_xpm(data);
		ft_handle_exit(data);
	}
}

void	ft_move_up(t_data *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		data->y--;
		if (data->map[data->y][data->x] == 'C')
			data->collected_items++;
		data->compteur_of_moves++;
		data->map[data->y][data->x] = 'P';
		if (data->y + 1 == data->exit_y && data->x == data->exit_x)
			data->map[data->y + 1][data->x] = 'E';
		else
			data->map[data->y + 1][data->x] = '0';
		ft_place_xpm(data);
		ft_handle_exit(data);
	}
}
