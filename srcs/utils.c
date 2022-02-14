/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:28:58 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/14 17:06:26 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	clearandquit(t_list **stacka)
{
	ft_lstclear(stacka);
	free(stacka);
	quit();
}

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

static void	indexage_last(t_list **stack_a, t_list *start)
{
	t_list	*secondary;
	int		count;

	secondary = start;
	count = 0;
	while (secondary->content != (*stack_a)->content)
	{
		if (secondary->content < (*stack_a)->content)
			count += 1;
		if (secondary->next == NULL)
			secondary = start;
		else
			secondary = secondary->next;
	}
	(*stack_a)->index = count;
}

void	indexage(t_list **stack_a)
{
	t_list	*start;
	t_list	*secondary;
	int		count;

	count = 0;
	start = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		secondary = (*stack_a)->next;
		count = 0;
		while (secondary->content != (*stack_a)->content)
		{
			if (secondary->content < (*stack_a)->content)
				count += 1;
			if (secondary->next == NULL)
				secondary = start;
			else
				secondary = secondary->next;
		}
		(*stack_a)->index = count;
		*stack_a = (*stack_a)->next;
	}
	indexage_last(stack_a, start);
	*stack_a = start;
}
