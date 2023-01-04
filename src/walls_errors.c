/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:05:25 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/04 23:42:32 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_x_walls(t_data *data)
{
	if (data->map[0][data->wall_x] != '1')
	{
		ft_printf("Error\nThere are no walls\n");
		exit(1);
	}
}

void	ft_check_walls_bottom(t_data *data, int size)
{
	if (data->map[size - 1][data->wall_x] != '1')
	{
		ft_printf("Error\nThere are no walls\n");
		exit(1);
	}
}

void	ft_check_y_walls(t_data *data)
{
	if (data->map[data->wall_y][0] != '1' || data->map[data->wall_y][data->wall_x - 2] != '1')
	{
		ft_printf("Error\nThere are no walls\n");
		exit(1);
	}
}
