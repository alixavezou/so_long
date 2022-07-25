/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:12:51 by alixavezou        #+#    #+#             */
/*   Updated: 2022/07/25 11:31:50 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "ft_printf/ft_printf.h"

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
	data->total_nb_col = ft_strlen(line);//colonnes dépendra du nb de char par ligne donc strlen de line
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
	int		fd;
	int		i;
	int		nb_line;
	int		nb_col;

	i = 0;
	ft_recup_map_size(data);
	nb_line = data->total_nb_line;
	nb_col = data->total_nb_col;
	data->map = malloc(sizeof(char *) * (nb_line + 1));//on recup la taille de l'immeuble
	if (!data->map)
		return ;
	fd = open("map/map.ber", O_RDONLY);
	while (nb_line > 0)
	{
		if (!data->map)
			return ;
		data->map[i] = malloc(sizeof(char) * (nb_col + 1));
		data->map[i] = get_next_line(fd);
		i++;
		nb_line--;
	}
	close(fd);
}

void	ft_errors_map(t_data *data)
{
	int		len;
	int		i;
	int		fd;

	i = 1;
	len = ft_strlen(data->map[0]);
	fd = open(data->file_name, O_RDONLY);
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

int main()
{
	t_data	data;
	data.file_name = "map/map.ber";
	ft_init_map(&data);
	ft_errors_map(&data);
	ft_check_walls(&data);
	ft_check_map(&data);
	printf("%s", data.map[0]);
	printf("%s", data.map[1]);
	printf("%s", data.map[2]);
	printf("%s", data.map[3]);
	printf("%s", data.map[4]);
	printf("%s", data.map[5]);
}
