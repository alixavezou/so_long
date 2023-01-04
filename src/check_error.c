/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:29:52 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/04 23:46:23 by alixavezou       ###   ########.fr       */
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
		ft_printf("ERROR\nInput file is not compatible\n");
		exit(1);
	}
}

int	ft_check_walls(t_data *data)
{
	int	size;

	if (!data->map)
		return (1);
	size = data->total_nb_line;
	data->wall_x = 0;
	while (data->map[0][data->wall_x + 1])
	{
		ft_check_x_walls(data);
		data->wall_x++;
	}
	data->wall_x = 0;
	while (data->map[size - 1][data->wall_x + 1])
	{
		ft_check_walls_bottom(data, size);
		data->wall_x++;
	}
	data->wall_y = 1;
	while (data->wall_y <= size - 2)
	{
		data->wall_x = ft_strlen(data->map[data->wall_y]);
		ft_check_y_walls(data);
		data->wall_y++;
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
			ft_printf("Error\nWrong nb of columns\n");
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

int	ft_check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			check_player(data, i, j);
			check_sortie(data, i, j);
			check_empty_space(data, i, j);
			ft_check_items(data, i, j);
			j++;
		}
		i++;
	}
	data->total_collectibles = data->collectible;
	if (data->player == 0 || data->player > 1 || data->sortie == 0 || data->sortie > 1 || data->collectible == 0 || data->empty == 0)
	{
		ft_printf("Error\nMap is not complete\n");
		exit(1);
	}
	data->is_valid_path = ft_backtrack(data->player_y, data->player_x, data);
	ft_check_valid_path(data);
	return (0);
}
