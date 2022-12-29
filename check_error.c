/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:29:52 by alixavezou        #+#    #+#             */
/*   Updated: 2022/12/29 16:25:40 by alixavezou       ###   ########.fr       */
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
		printf("ERROR\nInput file is not compatible\n");
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
		x = ft_strlen(data->map[y]); // strlen est la taille de la string en question - on ne veut pas la taille du tableau
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
			printf("Error\nWrong nb of columns\n");
			exit(1);
		}
		i++;
	}
}

void print_map(t_data *data)
{
	int i = 0;

	while(data->map){
		printf("%s", data->map[i++]);
	}
}
// Perform a depth-first search of the map starting at the player's current position
int	ft_backtrack(int row, int col, t_data *data) {

	printf("Position row: %d , col: %d \n",row, col);
	// print_map(data);
	// If we have reached the exit and collected all of the items, return true
  	if (row ==  data->exit_y && col ==  data->exit_x && data->collectibles_items ==  data->total_collectibles) {
    	return (1);
  	}
  	// If we have stepped outside the bounds of the map or encountered a wall, return false
  	if (row < 0 || row >= data->total_nb_line || col < 0 || col >= data->total_nb_col || data->map[row][col] == '1') {
    	return (0);
  	}
  // Mark the current location as visited
 	data->map[row][col] = 'V';
	// If we find a collectible we increment the counter
	if (data->map[row][col] == 'C')
		data->collectibles_items++;
  // Check the four adjacent locations (up, down, left, right)
  	if (ft_backtrack(row - 1, col, data) || ft_backtrack(row + 1, col, data) || ft_backtrack(row, col - 1, data) || ft_backtrack(row, col + 1, data)) {
    	return (1);
  }

  // If none of the adjacent locations led to a valid path, backtrack
  	data->map[row][col] = '0'; // 0 for empty space
  	return (0);
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
			{
				data->player_x = j;
				data->player_y = i;
				player++;
			}

			if (data->map[i][j] == 'E')
			{
				data->exit_x = j;
				data->exit_y = i;
				sortie++;
			}
			if (data->map[i][j] == '0')
				empty++;
			if (data->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	data->total_collectibles = collectible;
	if (player == 0 || player > 1 || sortie == 0 || sortie > 1 || collectible == 0 || empty == 0)
	{
		printf("Error\nMap is not complete\n");
		exit(1);
	}
	return (0);
}
