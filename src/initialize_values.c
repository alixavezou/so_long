/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:01:12 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/05 01:21:32 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_values(t_data *data)
{
	data->file_name = "map/map.ber";
	data->mlx_ptr = mlx_init();
	data->compteur_of_moves = 0;
	data->collected_items = 0;
	data->collectible_items = 0;
	data->found_exit = 0;
	data->is_valid_path = 0;
	data->player = 0;
	data->empty = 0;
	data->collectible = 0;
	data->sortie = 0;
}

