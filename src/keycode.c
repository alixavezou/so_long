/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:38:41 by alixavezou        #+#    #+#             */
/*   Updated: 2022/12/31 19:02:55 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	ft_get_player_position(data);
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit (1);
	}
	if ((keycode == GO_RIGHT || keycode == D_KEY) && data->map[data->y][data->x + 1] != '1')
	{
		data->x++;
		if (data->map[data->y][data->x + 1] == 'C')
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
	if ((keycode == GO_LEFT || keycode == A_KEY) && data->map[data->y][data->x - 1] != '1')
	{
		data->x--;
		if (data->map[data->y][data->x - 1] == 'C')
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
	if ((keycode == GO_DOWN || keycode == S_KEY) && data->map[data->y + 1][data->x] != '1')
	{
		data->y++;
		if (data->map[data->y + 1][data->x] == 'C')
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
	if ((keycode == GO_UP || keycode == W_KEY) && data->map[data->y - 1][data->x] != '1')
	{
		data->y--;
		if (data->map[data->y - 1][data->x] == 'C')
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
	printf("Number of moves: %d\n", data->compteur_of_moves);
	return (0);
}

void	ft_handle_exit(t_data *data)
{
	if (data->y == data->exit_y && data->x == data->exit_x)
	{
		if (data->collected_items < data->total_collectibles)
		{
			printf("You need to collect all the items first!\n");
			return ;
		}
		else
		{
			if (data->collected_items == data->total_collectibles)
			{
				printf("You finished the game in: %d moves!\n", data->compteur_of_moves);
				mlx_destroy_window(data->mlx_ptr, data->mlx_win);
				ft_free_map(data->map);
				ft_free_map(data->map_cpy);
				exit (1);
			}
		}
	}
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i++]);
	}
	free (map);
}
