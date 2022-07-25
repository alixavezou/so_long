/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:37:14 by alixavezou        #+#    #+#             */
/*   Updated: 2022/07/26 01:31:26 by alixavezou       ###   ########.fr       */
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

	while (data->map[i])
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')//si le 1er char de map[0] == 1
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_wall, 32 * j, 32 * i);
			j++;
		}
		i++; //on passe à map[1]
		j = 0;//on remet notre compteur au char[0] de map[0]
	}
}
