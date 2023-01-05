/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:05:25 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/05 17:56:59 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls(t_data *data)
{
	int	size;

	if (!data->map)
		return (1);
	size = data->total_nb_line;
	data->wall_x = 0;
	while (data->map[0][data->wall_x + 1])
	{
		ft_check_x_walls(data);
		data->wall_x++;
	}
	data->wall_x = 0;
	while (data->map[size - 1][data->wall_x + 1])
	{
		ft_check_walls_bottom(data, size);
		data->wall_x++;
	}
	data->wall_y = 1;
	while (data->wall_y <= size - 2)
	{
		data->wall_x = ft_strlen(data->map[data->wall_y]);
		ft_check_y_walls(data);
		data->wall_y++;
	}
	return (0);
}

void	ft_columns_size(t_data *data)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (len != (int)ft_strlen(data->map[i]))
		{
			ft_printf("Error\nWrong nb of columns\n");
			exit(1);
		}
		i++;
	}
}

void	ft_check_x_walls(t_data *data)
{
	if (data->map[0][data->wall_x] != '1')
	{
		ft_printf("Error\nMissing walls\n");
		exit(1);
	}
}

void	ft_check_walls_bottom(t_data *data, int size)
{
	if (data->map[size - 1][data->wall_x] != '1')
	{
		ft_printf("Error\nMissing walls\n");
		exit(1);
	}
}

void	ft_check_y_walls(t_data *data)
{
	if (data->map[data->wall_y][0] != '1'
	|| data->map[data->wall_y][data->wall_x - 2] != '1')
	{
		ft_printf("Error\nMissing walls\n");
		exit(1);
	}
}
