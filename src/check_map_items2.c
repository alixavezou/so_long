/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_items2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:58:08 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/05 18:05:17 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_is_complete(t_data *data)
{
	if (data->player == 0 || data->player > 1 || data->sortie == 0
		|| data->sortie > 1 || data->collectible == 0 || data->empty == 0)
	{
		ft_printf("Error\nMap is not complete\n");
		exit(1);
	}
}
