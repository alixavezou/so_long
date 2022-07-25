/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:29 by alixavezou        #+#    #+#             */
/*   Updated: 2022/07/26 01:06:33 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		heigth;
	t_data data;

	width = 0;
	heigth = 0;
	data.file_name = "map/map.ber";
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 300, "so_long");
	// data.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "walls.xpm", &width, &heigth);
	// mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 0, 0);
	if (data.mlx_win == NULL)
	{
		free (data.mlx_win);
		return (1);
	}
	/* Setup hooks on which we are going to trigger after the loop */
	// mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	// mlx_key_hook(data.mlx_win, &key_hook, &data);
	ft_init_map(&data);
	ft_errors_map(&data);
	ft_check_walls(&data);
	ft_check_map(&data);
	ft_place_xpm(&data);

	mlx_loop(data.mlx_ptr);
}
