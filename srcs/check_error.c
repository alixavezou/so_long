/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:29:52 by alixavezou        #+#    #+#             */
/*   Updated: 2022/02/04 16:30:11 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls(char **tab, char *file_name,int size) //je lui envoie le nombre de lignes
{
	int	x;
	int	y;

	if (!tab)
		return (1);
	x = 0;
	while (tab[0][x + 1]) //tant que le caractère à (x + 1) != 0 -> il n'ira pas sur le \n car après il y a un \0
	{
		if (tab[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (tab[size - 1][x + 1])
	{
		if (tab[size - 1][x] != '1')
			return (1);
		x++;
	}
	y = 1;
	while (y <= size - 2)
	{
		x = strlen(tab[y]); //strlen est la taille de la string en question - on ne veut pas la taille du tableau
		if(tab[y][0] != '1' || tab[y][x - 2] != '1') //je mets x - 2 car avant le \0, il y a un \n
			return (1);
		y++;
	}
	return (0);
}
