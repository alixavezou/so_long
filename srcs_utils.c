/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alixavezou <alixavezou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:08:39 by alixavezou        #+#    #+#             */
/*   Updated: 2022/08/10 11:53:07 by alixavezou       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//toutes les fonctions externes utilisées pour ce programme

int	ft_strncmp(char *s1, char *s2, unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
		return (0);
	while ((i + 1 < nb) && (s1[i] == s2[i]) && (s1[i] && s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
