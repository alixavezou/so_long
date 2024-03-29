/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:37:14 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_place_xpm(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				ft_draw_wall(data, i, j);
			if (data->map[i][j] == 'P')
				ft_draw_player(data, i, j);
			if (data->map[i][j] == 'E')
				ft_draw_exit(data, i, j);
			if (data->map[i][j] == '0')
				ft_draw_empty(data, i, j);
			if (data->map[i][j] == 'C')
				ft_draw_item(data, i, j);
			j++;
		}
		i++;
	}
}

void	ft_load_images(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->mlx_wall = mlx_xpm_file_to_image(data->mlx_ptr, WALLS_IMG, &w, &h);
	data->mlx_items = mlx_xpm_file_to_image(data->mlx_ptr, ITEM_IMG, &w, &h);
	data->mlx_player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_IMG, &w, &h);
	data->mlx_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_IMG, &w, &h);
	data->mlx_empty = mlx_xpm_file_to_image(data->mlx_ptr, EMPTY_IMG, &w, &h);
}

void	ft_destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mlx_wall);
	mlx_destroy_image(data->mlx_ptr, data->mlx_player);
	mlx_destroy_image(data->mlx_ptr, data->mlx_exit);
	mlx_destroy_image(data->mlx_ptr, data->mlx_empty);
	mlx_destroy_image(data->mlx_ptr, data->mlx_items);
}
