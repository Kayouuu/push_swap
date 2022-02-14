/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:28:58 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/14 09:39:36 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
int	ft_is_sorted(t_list *stack)
{
	int	last_nbr;
	int	is_sorted;

	last_nbr = stack->content;
	is_sorted = 1;
	stack = stack->next;
	while (stack != NULL)
	{
		if (last_nbr > stack->content)
			is_sorted = 0;
		last_nbr = stack->content;
		stack = stack->next;
	}
	return (is_sorted);
}
