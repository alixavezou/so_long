/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:52:37 by alixavezou        #+#    #+#             */
/*   Updated: 2022/12/23 16:33:47 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

// //tasks: faire bouger mon player d'une place vers la droite
// //taks: essayer de remplacer la case précédente par un espace vide
// recup la position de mon player

void	ft_get_player_position(t_data *data)
{
	int	i; // lignes (y)
	int	j; // cases (x)

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
			}
			j++;
		}
		i++;
	}
}

// int main()
// {
// 	t_data	data;
// 	data.file_name = "map/map.ber";
// 	// ft_init_map(&data);
// 	// ft_insidemap(&data);
// 	// ft_check_map(&data);
// 	// ft_get_player_position(&data);
// 	// mlx_key_hook(data.mlx_win, &key_hook, &data);
// 	// ft_get_player_position(&data);
// 	// printf("player position x = %i\n", data.x);
// 	// printf("player position y = %i\n", data.y);
// 	printf("%s", data.map[0]);
// 	printf("%s", data.map[1]);
// 	printf("%s", data.map[2]);
// 	printf("%s", data.map[3]);
// 	printf("%c", data.map[4][1]);
// 	printf("%s", data.map[5]);
// }
