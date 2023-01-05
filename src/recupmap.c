/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:12:51 by alixavezou        #+#    #+#             */
/*   Updated: 2023/01/05 13:25:57 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_recup_map_size(t_data *data)
{
	char	*line;
	int		fd;

	if (!data->file_name)
		exit (1);
	data->total_nb_line = 0;
	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
		exit (1);
	line = get_next_line(fd);
	data->total_nb_col = ft_strlen(line);
	while (line)
	{
		data->total_nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}

void	ft_init_map(t_data *data)
{
	int	i;
	int	nb_line;
	int	nb_col;

	i = 0;
	ft_recup_map_size(data);
	nb_line = data->total_nb_line;
	nb_col = data->total_nb_col;
	ft_allocate_maps(data, nb_line);
	ft_initialize_maps(data, nb_line, nb_col);
}

void	ft_allocate_maps(t_data *data, int nb_line)
{
	data->map = malloc(sizeof(char *) * (nb_line + 1));
	data->map_cpy = malloc(sizeof(char *) * (nb_line + 1));
	if (!data->map || !data->map_cpy)
		return ;
}

void	ft_initialize_maps(t_data *data, int nb_line, int nb_col)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("map/map.ber", O_RDONLY);
	while (nb_line > 0)
	{
		data->map[i] = malloc(sizeof(char) * (nb_col + 1));
		data->map_cpy[i] = malloc(sizeof(char) * (nb_col + 1));
		if (!data->map || !data->map_cpy)
			return ;
		data->map[i] = get_next_line(fd);
		data->map_cpy[i] = ft_strdup(data->map[i]);
		i++;
		nb_line--;
	}
	data->map[i] = NULL;
	data->map_cpy[i] = NULL;
	close(fd);
}
