/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:16:30 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:27:53 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_nbr_col(char *str)
{
	int	i;
	int	nbr_col;

	i = 0;
	nbr_col = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			nbr_col++;
		i++;
	}
	return	(nbr_col);
}