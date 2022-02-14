/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:31:58 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/25 14:17:26 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Radix algorithm	*/

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

static int	ft_nbr_size(int n)
{
	int	size;
	int	nbr;

	size = 0;
	nbr = n;
	if (nbr == -2147483647 - 1)
		return (11);
	if (nbr < 0)
	{
		nbr *= -1;
		size++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		size++;
	}
	size++;
	return (size);
}

int	*count_bits(int *tab)
{
	int	i;
	int	j;
	int	num;
	int	**splitted_digits;

	i = 0;
	splitted_digits = malloc(sizeof(int *) * (10));
	while (tab[i])
	{
		num = tab[i];
		splitted_digits[i] = malloc(sizeof(int) * (ft_nbr_size(num) + 1));
		j = ft_nbr_size(num) - 1;
		splitted_digits[i][j + 1] = NULL;
		while (num > 0)
		{
			splitted_digits[i][j] = num % 10;
			num = num / 10;
			j--;
		}
		i++;
	}
	splitted_digits[i] = malloc(sizeof(int));
	splitted_digits[i][0] = NULL;
	return (splitted_digits);
}

int	*radix(int *tab)
{
	int	*sorted_tab;
	int	**new_tab;

	sorted_tab = malloc(sizeof(int) * (10 + 1));
	new_tab = count_bits(tab);
	return (sorted_tab);
}
