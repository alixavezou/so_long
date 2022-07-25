/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:29:52 by alixavezou        #+#    #+#             */
/*   Updated: 2022/07/25 18:59:11 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

int	ft_check_walls(t_data *data)
{
	int	x;
	int	y;
	int	size;

	if (!data->map)
		return (1);
	size = data->total_nb_line;
	x = 0;
	while (data->map[0][x + 1]) //tant que le caractère à (x + 1) != 0 -> il n'ira pas sur le \n car après il y a un \0
	{
		if (data->map[0][x] != '1')
		{
			printf("Error\nThere are no walls\n");
			exit(1);
		}
		x++;
	}
	x = 0;
	while (data->map[size - 1][x + 1])
	{
		if (data->map[size - 1][x] != '1')
		{
			printf("Error\nThere are no walls\n");
			exit(1);
		}
		x++;
	}
	y = 1;
	while (y <= size - 2)
	{
		x = ft_strlen(data->map[y]); //strlen est la taille de la string en question - on ne veut pas la taille du tableau
		if(data->map[y][0] != '1' || data->map[y][x - 2] != '1') //je mets x - 2 car avant le \0, il y a un \n
		{
			printf("Error\nThere are no walls\n");
			exit(1);
		}
		y++;
	}
	return (0);
}

void	ft_errors_map(t_data *data)
{
	int		len;
	int		i;
	int		fd;

	i = 1;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (len != ft_strlen(data->map[i]))
		{
			printf("wrong nb of columns\n");
			exit(1);
		}
		i++;
	}
}

int	ft_check_map(t_data *data)
{
	int	i; //un compteur qui change de ligne
	int	j; //un compteur qui s'incrémente dans chaque ligne
	int	player;
	int	collectible;
	int	sortie;
	int	empty;

	i = 0;
	player = 0;
	collectible = 0;
	sortie = 0;
	empty = 0;

	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
				player++;
			if (data->map[i][j] == 'E')
				sortie++;
			if (data->map[i][j] == '0')
				empty++;
			if (data->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (player > 1 || sortie > 1 || collectible == 0 || empty == 0)
	{

		printf("Map is not right p=%d, s=%d, c=%d, e=%d\n",player, sortie, collectible, empty);
		exit(1);
	}
	return (0);
}
//TO-DO:
//On veut afficher notre map
//Il va falloir afficher dans le shell chaque pas du player
