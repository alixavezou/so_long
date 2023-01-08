/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insidemap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:54:56 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_insidemap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
			&& data->map[i][j] != 'E' && data->map[i][j] != 'C'
			&& data->map[i][j] != 'P' && data->map[i][j] != '\n')
			{
				ft_free_map(data->map);
				ft_free_map(data->map_cpy);
				ft_printf("Error\nMap must only contains 1, C, 0, P & E\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
