/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:29:52 by alixavezou        #+#    #+#             */
/*   Updated: 2022/08/11 00:22:38 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

void file_error(t_data *data)
{
	int len;
	char *last_four;

	len = ft_strlen(data->file_name);
	last_four = &(data->file_name)[len - 4];
	if (len < 5 || ft_strncmp(".ber", last_four, 5) != 0)
	{
		printf("ERROR : input file is not compatible");
		exit(1);
	}
}

int ft_check_walls(t_data *data)
{
	int x;
	int y;
	int size;

	if (!data->map)
		return (1);
	size = data->total_nb_line;
	x = 0;
	while (data->map[0][x + 1]) // tant que le caractère à (x + 1) != 0 -> il n'ira pas sur le \n car après il y a un \0
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
		x = ft_strlen(data->map[y]);							  // strlen est la taille de la string en question - on ne veut pas la taille du tableau
		if (data->map[y][0] != '1' || data->map[y][x - 2] != '1') // je mets x - 2 car avant le \0, il y a un \n
		{
			printf("Error\nThere are no walls\n");
			exit(1);
		}
		y++;
	}
	return (0);
}

void ft_columns_size(t_data *data)
{
	int len;
	int i;
	int fd;

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

int ft_check_map(t_data *data)
{
	int i; // un compteur qui change de ligne
	int j; // un compteur qui s'incrémente dans chaque ligne
	int player;
	int collectible;
	int sortie;
	int empty;

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
	if (player == 0 || sortie == 0 || collectible == 0 || empty == 0)
	{
		printf("Map is not complete\n");
		exit(1);
	}
	return (0);
}

// TO-DO:
// Il va falloir afficher dans le shell chaque pas du player
// Il faut faire bouger notre player
// vérifier que la window s'adapte à la taille de la map
// changer les printf avec ma fonction printf
// Il faut bloquer la map avec seulement E, P, 0, C
