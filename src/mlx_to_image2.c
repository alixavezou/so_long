/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_image2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:19:47 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw_wall(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_wall, 32 * j, 32 * i);
	if (!data->mlx_wall)
	{
		ft_printf("Error\nWrong conversion xpm to win\n");
		return (1);
	}
	return (0);
}

int	ft_draw_player(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_player, 32 * j, 32 * i);
	if (!data->mlx_player)
	{
		ft_printf("Error\nWrong conversion xpm to win\n");
		return (1);
	}
	return (0);
}

int	ft_draw_exit(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_exit, 32 * j, 32 * i);
	if (!data->mlx_exit)
	{
		ft_printf("Error\nWrong conversion xpm to win\n");
		return (1);
	}
	return (0);
}

int	ft_draw_empty(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_empty, 32 * j, 32 * i);
	if (!data->mlx_empty)
	{
		ft_printf("Error\nWrong conversion xpm to win\n");
		return (1);
	}
	return (0);
}

int	ft_draw_item(t_data *data, int i, int j)
{
	mlx_put_image_to_window
	(data->mlx_ptr, data->mlx_win, data->mlx_items, 32 * j, 32 * i);
	if (!data->mlx_items)
	{
		ft_printf("Error\nWrong conversion xpm to win\n");
		return (1);
	}
	return (0);
}
