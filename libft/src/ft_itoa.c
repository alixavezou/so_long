/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavezou <aavezou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:27:58 by aavezou           #+#    #+#             */
/*   Updated: 2023/01/08 23:24:25 by aavezou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		n = n * -1;
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count = count + 1;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;

	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	i = ft_count(n);
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	i--;
	if (n == 0)
		dest[i] = 48;
	if (n < 0)
	{
		dest[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		dest[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (dest);
}
