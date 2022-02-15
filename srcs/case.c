/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:51:50 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/15 14:05:17 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	which_case(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 3)
		case_three(stack_a);
	else if (size == 5)
		case_five(stack_a, stack_b);
	else if (size == 2)
		sa(stack_a);
	else
		radix(stack_a, stack_b);
}

void	case_three(t_list **stack_a)
{
	if ((*stack_a)->next->content < (*stack_a)->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		sa(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->next->content)
		ra(stack_a);
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->content)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->next->content > (*stack_a)->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		rra(stack_a);
}

void	case_five_rotate(t_list **stack_a, t_list *start, int n)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	min = 2147483647;
	while (i++ < n)
	{
		if ((*stack_a)->content < min)
		{
			min = (*stack_a)->content;
			pos = i;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = start;
	while ((*stack_a)->content != min)
	{
		if (pos <= 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	case_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*start;

	start = *stack_a;
	case_five_rotate(stack_a, start, 5);
	pb(stack_a, stack_b);
	start = *stack_a;
	case_five_rotate(stack_a, start, 4);
	pb(stack_a, stack_b);
	case_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
