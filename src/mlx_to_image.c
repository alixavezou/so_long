/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:37:14 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/05 13:43:48 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_place_xpm(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	ft_load_images(data);
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
	int	width;
	int	height;

	width = 0;
	height = 0;
	data->mlx_wall = mlx_xpm_file_to_image(data->mlx_ptr, WALLS_IMAGE, &width, &height);
	data->mlx_items = mlx_xpm_file_to_image(data->mlx_ptr, ITEMS_IMAGE, &width, &height);
	data->mlx_player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_IMAGE, &width, &height);
	data->mlx_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_IMAGE, &width, &height);
	data->mlx_empty = mlx_xpm_file_to_image(data->mlx_ptr, EMPTY_IMAGE, &width, &height);
}

void	ft_draw_wall(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_wall, 32 * j, 32 * i);
	if (!data->mlx_wall)
		ft_printf("Error\nWrong conversion xpm to win\n");
}

void	ft_draw_player(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_player, 32 * j, 32 * i);
	if (!data->mlx_player)
		ft_printf("Error\nWrong conversion xpm to win\n");
}

void	ft_draw_exit(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_exit, 32 * j, 32 * i);
	if (!data->mlx_exit)
		ft_printf("Error\nWrong conversion xpm to win\n");
}

void	ft_draw_empty(t_data *data, int i, int j)
{
	 mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_empty, 32 * j, 32 * i);
	if (!data->mlx_empty)
		ft_printf("Error\nWrong conversion xpm to win\n");
}

void	ft_draw_item(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_items, 32 * j, 32 * i);
	if (!data->mlx_items)
		ft_printf("Error\nWrong conversion xpm to win\n");
}
