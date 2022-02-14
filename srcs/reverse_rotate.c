/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:27:26 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/02 16:50:14 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_list **stacka)
{
	t_list	*tmp;
	t_list	*last_node;

	tmp = ft_lstlast(*stacka);
	ft_lstadd_front(stacka, ft_lstnew(tmp->content));
	tmp = *stacka;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	free(last_node);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stackb)
{
	t_list	*tmp;
	t_list	*last_node;

	tmp = ft_lstlast(*stackb);
	ft_lstadd_front(stackb, ft_lstnew(tmp->content));
	tmp = *stackb;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	free(last_node);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stacka, t_list **stackb)
{
	t_list	*tmp;
	t_list	*last_node;

	tmp = ft_lstlast(*stacka);
	ft_lstadd_front(stacka, ft_lstnew(tmp->content));
	tmp = *stacka;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	free(last_node);
	tmp = ft_lstlast(*stackb);
	ft_lstadd_front(stackb, ft_lstnew(tmp->content));
	tmp = *stackb;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = NULL;
	free(last_node);
	ft_putendl_fd("rrr", 1);
}
