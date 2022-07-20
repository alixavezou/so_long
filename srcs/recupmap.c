/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:12:51 by alixavezou        #+#    #+#             */
/*   Updated: 2022/07/20 16:06:51 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_recup_map_size(char *file_name)
{
	char	*line;
	int		total_nb_line;
	int		fd;

	if (!file_name)
		exit (1);
	total_nb_line = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (1);
	line = get_next_line(fd);
	while (line)
	{
		total_nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	return (total_nb_line);
}

void	ft_print_map(env *so_long)
{
	int		fd;
	int		i;
	int		nb_line;

	i = 0;
	nb_line = ft_recup_map_size("map/map.ber");
	if (nb_line == -1)
		return ;
	fd = open("map/map.ber", O_RDONLY);
	so_long->map[i] = malloc(sizeof(char *) * (nb_line + 1));
	if (!so_long->map)
		return ;
	while (nb_line > 0)
	{
		so_long->map[i] = get_next_line(fd);
		i++;
		nb_line--;
	}
	so_long->map[i] = 0;
	close(fd);
}

// int main()
// {
// 	env		so_long;

// 	ft_print_map(&so_long);
// 	printf("%s", so_long.map[0]);
// 		printf("%s", so_long.map[1]);
// 	printf("%s", so_long.map[2]);
// 	printf("%s", so_long.map[3]);
// 	printf("%s", so_long.map[4]);
// 		printf("%s", so_long.map[5]);
// }
