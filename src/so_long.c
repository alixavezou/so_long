/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:29 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/04 15:21:33 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;

	data.file_name = "map/map.ber";
	data.mlx_ptr = mlx_init();
	data.compteur_of_moves = 0;
	data.total_collectibles = 0;
	data.collected_items = 0;
	data.collectibles_items = 0;
	data.found_exit = 0;
	data.is_valid_path = 0;
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1088, 192, "so_long");
	if (data.mlx_win == NULL)
	{
		free (data.mlx_win);
		return (1);
	}
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	file_error(&data);
	ft_init_map(&data);
	ft_insidemap(&data);
	ft_columns_size(&data);
	ft_check_walls(&data);
	ft_check_map(&data);
	ft_place_xpm(&data);
	ft_handle_exit(&data);
	mlx_loop(data.mlx_ptr);
}
