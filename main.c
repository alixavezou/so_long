/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:25:29 by alixavezou        #+#    #+#             */
/*   Updated: 2022/07/22 13:35:28 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;

	t_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 300, "so_long");
	if (data.mlx_win == NULL)
	{
		free (data.mlx_win);
		return (1);
	}
	/* Setup hooks on which we are going to trigger after the loop */
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);

	mlx_loop(data.mlx_ptr);
}
