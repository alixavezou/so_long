/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:19:23 by alixavezou        #+#    #+#             */
/*   Updated: 2022/11/09 17:25:30 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "ft_printf/ft_printf.h"

void	ft_initialize_ptr(t_data *data)
{
	int	width;
	int	heigth;

	width = 0;
	heigth = 0;

	data->mlx_wall = mlx_xpm_file_to_image(data->mlx_ptr, WALLS_IMAGE, &width, &heigth);
	data->mlx_items = mlx_xpm_file_to_image(data->mlx_ptr, ITEMS_IMAGE, &width, &heigth);
	data->mlx_player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_IMAGE, &width, &heigth);
	data->mlx_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_IMAGE, &width, &heigth);
	data->mlx_empty = mlx_xpm_file_to_image(data->mlx_ptr, EMPTY_IMAGE, &width, &heigth);
}
