/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_image2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:19:47 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/05 17:51:53 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_wall(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_wall, 32 * j, 32 * i);
	if (!data->mlx_wall)
		ft_printf("Error\nWrong conversion xpm to win\n");
}

void	ft_draw_player(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_player, 32 * j, 32 * i);
	if (!data->mlx_player)
		ft_printf("Error\nWrong conversion xpm to win\n");
}

void	ft_draw_exit(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_exit, 32 * j, 32 * i);
	if (!data->mlx_exit)
		ft_printf("Error\nWrong conversion xpm to win\n");
}

void	ft_draw_empty(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_empty, 32 * j, 32 * i);
	if (!data->mlx_empty)
		ft_printf("Error\nWrong conversion xpm to win\n");
}

void	ft_draw_item(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_items, 32 * j, 32 * i);
	if (!data->mlx_items)
		ft_printf("Error\nWrong conversion xpm to win\n");
}
