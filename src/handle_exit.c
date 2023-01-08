/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:55:04 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
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
				ft_printf("See you soon!\n");
				ft_close(data);
			}
		}
	}
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_close(t_data *data)
{
	ft_free_map(data->map);
	ft_free_map(data->map_cpy);
	ft_destroy_image(data);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}
