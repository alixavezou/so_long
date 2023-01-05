/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:55:04 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/05 12:55:11 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_exit(t_data *data)
{
	if (data->y == data->exit_y && data->x == data->exit_x)
	{
		if (data->collected_items < data->collectible)
		{
			ft_printf("You need to collect all the items first!\n");
			return ;
		}
		else
		{
			if (data->collected_items == data->collectible)
			{
				ft_printf("You finished the game in: %d moves!\n", data->compteur_of_moves);
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
