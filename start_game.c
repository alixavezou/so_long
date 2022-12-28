/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:37:14 by alixavezou        #+#    #+#             */
/*   Updated: 2022/12/28 14:28:44 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_place_xpm(t_data *data)
{
	int		width;
	int		heigth;
	int		i; //ligne
	int		j; //char

	width = 0;
	heigth = 0;
	i = 0;
	j = 0;
	data->mlx_wall = mlx_xpm_file_to_image(data->mlx_ptr, WALLS_IMAGE, &width, &heigth);
	data->mlx_items = mlx_xpm_file_to_image(data->mlx_ptr, ITEMS_IMAGE, &width, &heigth);
	data->mlx_player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_IMAGE, &width, &heigth);
	data->mlx_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_IMAGE, &width, &heigth);
	data->mlx_empty = mlx_xpm_file_to_image(data->mlx_ptr, EMPTY_IMAGE, &width, &heigth);
	while (data->map[i])
	{
		j = 0;//on remet notre compteur au char[0] de map[0]
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')//si le 1er char de map[0] == 1
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_wall, 32 * j, 32 * i); //* 32 pixels
			if (!data->mlx_wall)
				printf("Error\nWrong conversion xpm to win\n");
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_player, 32 * j, 32 * i);
			if (!data->mlx_player)
				printf("Error\nWrong conversion xpm to win\n");
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_exit, 32 * j, 32 * i);
			if (!data->mlx_exit)
				printf("Error\nWrong conversion xpm to win\n");
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_empty, 32 * j, 32 * i);
			if (!data->mlx_empty)
				printf("Error\nWrong conversion xpm to win\n");
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_items, 32 * j, 32 * i);
			if (!data->mlx_items)
				printf("Error\nWrong conversion xpm to win\n");
			j++;
		}
		i++;
	}
}
