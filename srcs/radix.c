/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:48 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/15 09:44:37 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_bit_one(int current_number, int i)
{
	if (current_number & (1 << (i - 1)))
		return (1);
	else
		return (0);
}

int	get_max_digits(t_list *stack_a)
{
	t_list	*tmp;
	int		max;
	int		count;

	tmp = stack_a;
	max = -1;
	count = 1;
	while (tmp != NULL)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
		}
		tmp = tmp->next;
	}
	while (max)
	{
		count += 1;
		max >>= 1;
	}
	return (count);
}

t_list	*get_min_index(t_list *stack)
{
	int	min_index;

	min_index = INT_MAX;
	while (stack != NULL)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (stack);
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		size;
	int		current_digits;

	size = ft_lstsize(*stack_a);
	current_digits = 0;
	while (ft_is_sorted(*stack_a) == 0)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> current_digits) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		current_digits += 1;
	}
}
