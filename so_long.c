/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:29 by alixavezou        #+#    #+#             */
/*   Updated: 2022/12/29 22:03:19 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	data;
	int		result;

	data.file_name = "map/map.ber";
	data.mlx_ptr = mlx_init();
	data.compteur_of_moves = 0;
	data.total_collectibles = 0;
	data.collected_items = 0;
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1088, 192, "so_long");
	if (data.mlx_win == NULL)
	{
		free (data.mlx_win);
		return (1);
	}
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	ft_init_map(&data);
	file_error(&data);
	ft_insidemap(&data);
	ft_columns_size(&data);
	ft_check_walls(&data);
	ft_check_map(&data);
	ft_place_xpm(&data);
	result = ft_backtrack(data.player_y, data.player_x, &data);
	if (result == 1)
	{
		printf("There is a good path in the map!\n");
	}
	else
	{
		if (result == 0)
		{
			printf("There is no good path to reach exit in this map\n");
			exit (1);
		}
	}
	ft_handle_exit(&data);
	mlx_loop(data.mlx_ptr);
}
