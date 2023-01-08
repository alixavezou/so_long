/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:29:52 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_error(t_data *data)
{
	int		len;
	char	*last_four;

	len = ft_strlen(data->file_name);
	last_four = &(data->file_name)[len - 4];
	if (len < 5 || ft_strncmp(".ber", last_four, 5) != 0)
	{
		ft_printf("Error\nInput file is not compatible\n");
		exit(1);
	}
}

int	ft_backtrack(int row, int col, t_data *data)
{
	return (ft_backtrack_part_1(row, col, data));
}

int	ft_backtrack_part_1(int row, int col, t_data *data)
{
	if (row == data->exit_y && col == data->exit_x)
		data->found_exit = 1;
	if (data->found_exit == 1 && data->collectible_items == data->collectible)
		return (1);
	if (row < 0 || row >= data->total_nb_line
		|| col < 0 || col >= data->total_nb_col
		|| data->map_cpy[row][col] == '1')
		return (0);
	if (data->map_cpy[row][col] == 'V')
		return (0);
	data->map_cpy[row][col] = 'V';
	if (data->map[row][col] == 'C')
		data->collectible_items++;
	return (ft_backtrack_part_2(row, col, data));
}

int	ft_backtrack_part_2(int row, int col, t_data *data)
{
	int	failed_paths;

	failed_paths = 0;
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
			ft_check_player(data, i, j);
			ft_check_sortie(data, i, j);
			ft_check_empty_space(data, i, j);
			ft_check_items(data, i, j);
			j++;
		}
		i++;
	}
	ft_check_map_is_complete(data);
	data->is_valid_path = ft_backtrack(data->player_y, data->player_x, data);
	ft_check_valid_path(data);
	return (0);
}
