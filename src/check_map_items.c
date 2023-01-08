/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:47:34 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_player(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		data->player_x = j;
		data->player_y = i;
		data->player++;
	}
}

void	ft_check_sortie(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'E')
	{
		data->exit_x = j;
		data->exit_y = i;
		data->sortie++;
	}
}

void	ft_check_empty_space(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0')
		data->empty++;
}

void	ft_check_items(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
		data->collectible++;
}

void	ft_check_valid_path(t_data *data)
{
	if (data->is_valid_path == 1)
		ft_printf("There is a valid path in the map!\n");
	else
	{
		ft_free_map(data->map);
		ft_free_map(data->map_cpy);
		ft_printf("Error\nThere is no valid path!\n");
		exit(1);
	}
}
