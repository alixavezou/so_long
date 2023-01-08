/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:29 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Error\nWrong number of arguments!\n");
		return (1);
	}
	ft_initialize_values(&data, av[1]);
	ft_file_error(&data);
	ft_init_map(&data);
	if (ft_check_if_map_is_empty(&data) == 1)
		return (1);
	ft_insidemap(&data);
	ft_columns_size(&data);
	ft_check_walls(&data);
	ft_check_map(&data);
	if (init_window(&data))
		return (1);
	ft_load_images(&data);
	ft_place_xpm(&data);
	ft_handle_exit(&data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
}

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->total_nb_col * 32, \
	data->total_nb_line * 32, "so_long");
	if (data->mlx_win == NULL)
	{
		free (data->mlx_win);
		return (1);
	}
	return (0);
}
