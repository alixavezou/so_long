/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:29:52 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/04 18:41:35 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_error(t_data *data)
{
	int		len;
	char	*last_four;

	len = ft_strlen(data->file_name);
	last_four = &(data->file_name)[len - 4];
	if (len < 5 || ft_strncmp(".ber", last_four, 5) != 0)
	{
		printf("ERROR\nInput file is not compatible\n");
		exit(1);
	}
}

int	ft_check_walls(t_data *data)
{
	int	x;
	int	y;
	int	size;

	if (!data->map)
		return (1);
	size = data->total_nb_line;
	x = 0;
	while (data->map[0][x + 1])
	{
		if (data->map[0][x] != '1')
		{
			ft_printf("Error\nThere are no walls\n");
			exit(1);
		}
		x++;
	}
	x = 0;
	while (data->map[size - 1][x + 1])
	{
		if (data->map[size - 1][x] != '1')
		{
			ft_printf("Error\nThere are no walls\n");
			exit(1);
		}
		x++;
	}
	y = 1;
	while (y <= size - 2)
	{
		x = ft_strlen(data->map[y]);
		if (data->map[y][0] != '1' || data->map[y][x - 2] != '1')
		{
			ft_printf("Error\nThere are no walls\n");
			exit(1);
		}
		y++;
	}
	return (0);
}

void	ft_columns_size(t_data *data)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (len != (int)ft_strlen(data->map[i]))
		{
			printf("Error\nWrong nb of columns\n");
			exit(1);
		}
		i++;
	}
}

int	ft_backtrack(int row, int col, t_data *data)
{
	if (row == data->exit_y && col == data->exit_x)
		data->found_exit = 1;
	if (data->found_exit == 1 && data->collectibles_items == data->total_collectibles)
			return (1);
	if (row < 0 || row >= data->total_nb_line || col < 0 || col >= data->total_nb_col || data->map_cpy[row][col] == '1')
		return (0);
	if (data->map_cpy[row][col] == 'V')
		return 0;
	data->map_cpy[row][col] = 'V';
	if (data->map[row][col] == 'C')
		data->collectibles_items++;
	int failed_paths = 0;
	if (ft_backtrack(row - 1, col, data) == 0)
		failed_paths++;
	else
		return (1);
	if (ft_backtrack(row + 1, col, data) == 0)
		failed_paths++;
	else
		return (1);
	if (ft_backtrack(row, col - 1, data) == 0)
		failed_paths++;
	else
		return (1);
	if (ft_backtrack(row, col + 1, data) == 0)
		failed_paths++;
	else
		return (1);
	if (failed_paths == 4)
		return (0);
	data->map_cpy[row][col] = '0';
	return (0);
}

// int ft_exit_found(int row, int col, t_data *data)
// {
// 	return row == data->exit_y && col == data->exit_x;
// }

// int ft_is_valid_move(int row, int col, t_data *data)
// {
// 	return row >= 0 && row < data->total_nb_line && col >= 0 && col < data->total_nb_col && data->map_cpy[row][col] != '1';
// }

// int ft_backtrack(int row, int col, t_data *data)
// {
// 	printf("==========\n");
// 	printf("collec = %d\n", data->collectibles_items);
// 	print_map(data->map_cpy);
// 	printf("==========\n");
// 	int result;

// 	if (ft_exit_found(row, col, data))
// 	{
// 		data->found_exit = 1;
// 		return data->collectibles_items == data->total_collectibles;
// 	}
// 	if (data->map_cpy[row][col] == 'V' || !ft_is_valid_move(row, col, data))
// 		return 0;

// 	data->map_cpy[row][col] = 'V';
// 	if (data->map[row][col] == 'C')
// 		data->collectibles_items++;

// 	result = ft_backtrack(row - 1, col, data) || ft_backtrack(row + 1, col, data) || ft_backtrack(row, col - 1, data) || ft_backtrack(row, col + 1, data);
// 	if (!result)
// 		data->map_cpy[row][col] = '0';
// 	return result;
// }


int	ft_check_map(t_data *data)
{
	int	i;
	int	j;
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
		ft_printf("Error\nMap is not complete\n");
		exit(1);
	}
	data->is_valid_path = ft_backtrack(data->player_y, data->player_x, data);
	if (data->is_valid_path == 1)
	{
		printf("There is a good path in the map!\n");
	}
	else
	{
		ft_printf("There is no valid path!\n");
		exit(1);
	}
	return (0);
}
