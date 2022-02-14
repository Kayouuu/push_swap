/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:26:50 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/03 12:52:11 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_list **stacka)
{
	void	*tmp;

	ft_lstadd_back(stacka, ft_lstnew((*stacka)->content));
	tmp = *stacka;
	*stacka = (*stacka)->next;
	free(tmp);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stackb)
{
	void	*tmp;

	ft_lstadd_back(stackb, ft_lstnew((*stackb)->content));
	tmp = *stackb;
	*stackb = (*stackb)->next;
	free(tmp);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stacka, t_list **stackb)
{
	void	*tmp;

	ft_lstadd_back(stacka, ft_lstnew((*stacka)->content));
	tmp = *stacka;
	*stacka = (*stacka)->next;
	free(tmp);
	ft_lstadd_back(stackb, ft_lstnew((*stackb)->content));
	tmp = *stackb;
	*stackb = (*stackb)->next;
	free(tmp);
	ft_putendl_fd("rr", 1);
}
