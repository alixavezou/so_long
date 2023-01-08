/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_items2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:58:08 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_is_complete(t_data *data)
{
	if (data->player == 0 || data->player > 1 || data->sortie == 0
		|| data->sortie > 1 || data->collectible == 0 || data->empty == 0)
	{
		ft_free_map(data->map);
		ft_free_map(data->map_cpy);
		ft_printf("Error\nMap is not complete\n");
		exit(1);
	}
}
