/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:12:51 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_recup_map_size(t_data *data)
{
	char	*line;
	int		fd;

	if (!data->file_name)
	{
		ft_printf("Error\nThere is no path!\n");
		exit (1);
	}
	data->total_nb_line = 0;
	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nThere is no map named like this!\n");
		exit (1);
	}
	line = get_next_line(fd);
	if (line != NULL)
	{
		data->total_nb_col = ft_strlen(line) - 1;
		while (line)
		{
			data->total_nb_line++;
			free(line);
			line = get_next_line(fd);
		}
		free(line);
	}
	close (fd);
}

void	ft_init_map(t_data *data)
{
	int	nb_line;
	int	nb_col;

	(void)nb_col;
	ft_recup_map_size(data);
	if (data->total_nb_col == 0)
		return ;
	nb_line = data->total_nb_line;
	nb_col = data->total_nb_col;
	ft_allocate_maps(data, nb_line);
	ft_initialize_maps(data, nb_line);
}

void	ft_allocate_maps(t_data *data, int nb_line)
{
	data->map = (char **)malloc(sizeof(char *) * (nb_line + 1));
	if (!data->map)
		return ;
	data->map_cpy = (char **)malloc(sizeof(char *) * (nb_line + 1));
	if (!data->map_cpy)
	{
		ft_free_map(data->map);
		exit(1);
	}
}

void	ft_initialize_maps(t_data *data, int nb_line)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(data->file_name, O_RDONLY);
	while (nb_line > 0)
	{
		if (!data->map || !data->map_cpy)
			return ;
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
		{
			ft_free_map(data->map);
			ft_free_map(data->map_cpy);
			exit(1);
		}
		data->map_cpy[i] = ft_strdup(data->map[i]);
		i++;
		nb_line--;
	}
	data->map[i] = NULL;
	data->map_cpy[i] = NULL;
	close(fd);
}

int	ft_check_if_map_is_empty(t_data *data)
{
	if (data->map == NULL)
	{
		ft_printf("Error\nMap is empty!\n");
		return (1);
	}
	return (0);
}
