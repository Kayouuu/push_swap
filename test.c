/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:23:04 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/25 14:14:20 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

char	*ft_itoa(int n);
int		*radix(int	*tab);

int	main(void)
{
	int	i;
	int	*tab;
	int	*sorted_tab;

	tab = malloc(sizeof(int) * (5 + 1));
	tab[0] = 5;
	tab[1] = 81;
	tab[2] = 4;
	tab[3] = 9;
	tab[4] = 7;
	tab[5] = NULL;
	sorted_tab = radix(tab);
	return (0);
}
