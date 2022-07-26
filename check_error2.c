/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:54:56 by alixavezou        #+#    #+#             */
/*   Updated: 2022/08/11 00:10:29 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

void	ft_insidemap(t_data *data)
{
	int	i;//lines
	int	j;//char

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1' || data->map[i][j] == '0' || data->map[i][j] == 'E'
			|| data->map[i][j] == 'C' || data->map[i][j] == 'P' || data->map[i][j] == '\n' || data->map[i][j] == '\0')
			{
				j++;
			}
			else
			{
				 printf("map must only have 1, C, 0, P & E\n");
				 exit(1);
			}
		}
		i++;
	}
}
