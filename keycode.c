/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:38:41 by alixavezou        #+#    #+#             */
/*   Updated: 2022/12/25 22:23:41 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "ft_printf/ft_printf.h"

int	key_hook(int keycode, t_data *data)
{
	ft_get_player_position(data); //on recup la position du player
	if (keycode == ESC)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->map[data->y][data->x] == 'E')
	{
		printf("je rentre ici\n");
		if (data->collected_items < data->total_collectibles)
		{
			printf("You need to collect all the items before exiting the game!\n");
		}
		if (data->collected_items == data->total_collectibles)
		{
			printf("collected_items = %d\n", data->collected_items);
			printf("total_collectibles = %d\n", data->total_collectibles);
			printf("You have completed the game, well done!\n");
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		}
	}
	else
	{
		// printf("je rentre ici 2\n");
		if (keycode == GO_RIGHT && data->map[data->y][data->x + 1] != '1')
		{

			data->x++; //on fait bouger le player
			data->compteur++;
			data->map[data->y][data->x] = 'P'; //on lui assigne P à sa nouvelle position
			if (data->y == data->exit_y && data->x - 1 == data->exit_x)
				data->map[data->y][data->x - 1] = 'E';
			else
				data->map[data->y][data->x - 1] = '0'; //on remplace la case d'avant par un espace vide
			ft_place_xpm(data);
		}
		if (keycode == GO_LEFT && data->map[data->y][data->x - 1] != '1')
		{
			data->x--;
			data->compteur++;
			data->map[data->y][data->x] = 'P';
			if (data->y == data->exit_y && data->x + 1 == data->exit_x)
				data->map[data->y][data->x + 1] = 'E';
			else
				data->map[data->y][data->x + 1] = '0'; //on remplace la case d'avant par un espace vide
			ft_place_xpm(data);
		}
		if (keycode == GO_DOWN && data->map[data->y + 1][data->x] != '1')
		{
			data->y++;
			data->compteur++;
			data->map[data->y][data->x] = 'P';
			if (data->y - 1 == data->exit_y && data->x == data->exit_x) {
				data->map[data->y - 1][data->x] = 'E';
			}
			else {
				data->map[data->y - 1][data->x] = '0'; //on remplace la case d'avant par un espace vide
			}
			ft_place_xpm(data);
		}
		if (keycode == GO_UP && data->map[data->y - 1][data->x] != '1')
		{
			data->y--;
			data->compteur++;
			data->map[data->y][data->x] = 'P';
			if (data->y + 1 == data->exit_y && data->x == data->exit_x) {
				data->map[data->y + 1][data->x] = 'E';
			}
			else {
				data->map[data->y + 1][data->x] = '0'; //on remplace la case d'avant par un espace vide
			}
			ft_place_xpm(data);
		}
	}
	printf("Number of moves: %d\n", data->compteur);
	return (0);
}

int	ft_collected_items(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			j++;
			if (data->map[i][j] == 'C')
			{
				data->collected_items++;
				j++;
			}
		}
		i++;
	}
	return (0);
}

