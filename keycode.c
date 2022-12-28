/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:38:41 by alixavezou        #+#    #+#             */
/*   Updated: 2022/12/28 13:59:38 by alixavezou       ###   ########.fr       */
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
		data->x++; //on fait bouger le player
		if (data->map[data->y][data->x + 1] == 'C')
			data->collected_items++;
		data->compteur++;
		data->map[data->y][data->x] = 'P'; //on lui assigne P à sa nouvelle position
		if (data->y == data->exit_y && data->x - 1 == data->exit_x)
			data->map[data->y][data->x - 1] = 'E';
		else
			data->map[data->y][data->x - 1] = '0'; //on remplace la case d'avant par un espace vide
		ft_place_xpm(data);
		ft_handle_exit(data);
	}
	if (keycode == GO_LEFT && data->map[data->y][data->x - 1] != '1')
	{
		data->x--;
		if (data->map[data->y][data->x - 1] == 'C')
			data->collected_items++;
		data->compteur++;
		data->map[data->y][data->x] = 'P';
		if (data->y == data->exit_y && data->x + 1 == data->exit_x)
			data->map[data->y][data->x + 1] = 'E';
		else
			data->map[data->y][data->x + 1] = '0';
		ft_place_xpm(data);
		ft_handle_exit(data);
	}
	if (keycode == GO_DOWN && data->map[data->y + 1][data->x] != '1')
	{
		data->y++;
		if (data->map[data->y + 1][data->x] == 'C')
			data->collected_items++;
		data->compteur++;
		data->map[data->y][data->x] = 'P';
		if (data->y - 1 == data->exit_y && data->x == data->exit_x)
			data->map[data->y - 1][data->x] = 'E';
		else
			data->map[data->y - 1][data->x] = '0';
		ft_place_xpm(data);
		ft_handle_exit(data);
	}
	if (keycode == GO_UP && data->map[data->y - 1][data->x] != '1')
	{
		data->y--;
		if (data->map[data->y - 1][data->x] == 'C')
			data->collected_items++;
		data->compteur++;
		data->map[data->y][data->x] = 'P';
		if (data->y + 1 == data->exit_y && data->x == data->exit_x)
			data->map[data->y + 1][data->x] = 'E';
		else
			data->map[data->y + 1][data->x] = '0';
		ft_place_xpm(data);
		ft_handle_exit(data);
	}
	printf("Number of moves: %d\n", data->compteur);
	return (0);
}

void	ft_handle_exit(t_data *data)
{
	if ((data->y == data->exit_y) && (data->x == data->exit_x))
		if ((data->collected_items < data->total_collectibles))
		{
			printf("You need to collect all the items before exiting the game!\n");
			return ;
		}
		else if (data->collected_items == data->total_collectibles)
		{
			printf("You have completed the game, well done!\n");
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		}
}
