/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:29 by alixavezou        #+#    #+#             */
/*   Updated: 2022/11/20 18:55:53 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data data;

	data.file_name = "map/map.ber";
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1090, 190, "so_long");
	if (data.mlx_win == NULL)
	{
		free (data.mlx_win);
		return (1);
	}
	/* Setup hooks on which we are going to trigger after the loop */
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	ft_init_map(&data);
	file_error(&data);
	ft_insidemap(&data);
	ft_columns_size(&data);
	ft_check_walls(&data);
	ft_check_map(&data);
	ft_place_xpm(&data);

	mlx_loop(data.mlx_ptr);
}
