/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:01:12 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_values(t_data *data, char *filename)
{
	data->file_name = filename;
	data->map = NULL;
	data->map_cpy = NULL;
	data->compteur_of_moves = 0;
	data->collected_items = 0;
	data->collectible_items = 0;
	data->found_exit = 0;
	data->is_valid_path = 0;
	data->player = 0;
	data->empty = 0;
	data->collectible = 0;
	data->sortie = 0;
	data->total_nb_col = 0;
	data->total_nb_line = 0;
	data->x = 0;
	data->y = 0;
	data->exit_x = 0;
	data->exit_y = 0;
}
