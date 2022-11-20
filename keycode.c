/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:38:41 by alixavezou        #+#    #+#             */
/*   Updated: 2022/11/20 18:55:04 by alixavezou       ###   ########.fr       */
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
		data->map[data->y][data->x] = 'P'; //on lui assigne P à sa nouvelle position
		data->map[data->y][data->x - 1] = '0'; //on remplace la case d'avant par un espace vide
		ft_place_xpm(data);
	}
	if (keycode == GO_LEFT && data->map[data->y][data->x - 1] != '1')
	{
		data->x--;
		data->map[data->y][data->x] = 'P';
		data->map[data->y][data->x + 1] = '0';
		ft_place_xpm(data);
	}
	if (keycode == GO_DOWN && data->map[data->y + 1][data->x] != '1')
	{
		data->y++;
		data->map[data->y][data->x] = 'P';
		data->map[data->y - 1][data->x] = '0';
		ft_place_xpm(data);
	}
	if (keycode == GO_UP && data->map[data->y - 1][data->x] != '1')
	{
		data->y--;
		data->map[data->y][data->x] = 'P';
		data->map[data->y + 1][data->x] = '0';
		ft_place_xpm(data);
	}
	return (0);
}

// maintenant je veux faire une fonction qui compte les objets collectés pour savoir cb il y en a dans la map au total
// le player ne doit pas sortir tant que les objets collectés ne sont pas tous collectés
// si le player == exit alors mlx_destroy_window

// int	ft_collected_items(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (data->map[i] != NULL)
// 	{
// 		while (data->map[i][j] != '\0')
// 		{
// 			// printf("map[i] = %s\n", data->map[i]);
// 			// printf("map2 = %s\n", data->map[j]);
// 			if (data->map[i][j] == 'C')
// 			{
// 				printf("map[i] = %s\n", data->map[i]);
// 				data->collected_items++;
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	printf("collectible = %d\n", data->collected_items);
// 	return (0);
// }
