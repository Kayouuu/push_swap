/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:02:54 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/12 15:56:43 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_list **stacka)
{
	int	tmp;

	if (*stacka && (*stacka)->next != NULL)
	{
		tmp = (*stacka)->content;
		(*stacka)->content = ((*stacka)->next)->content;
		(*stacka)->next->content = tmp;
	}
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stackb)
{
	int	tmp;

	if ((*stackb) && (*stackb)->next != NULL)
	{
		tmp = (*stackb)->content;
		(*stackb)->content = ((*stackb)->next)->content;
		(*stackb)->next->content = tmp;
	}
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stacka, t_list **stackb)
{
	int	tmp;

	if ((*stacka) && (*stacka)->next != NULL)
	{
		tmp = (*stacka)->content;
		(*stacka)->content = ((*stacka)->next)->content;
		(*stacka)->next->content = tmp;
	}
	if ((*stackb) && (*stackb)->next != NULL)
	{
		tmp = (*stackb)->content;
		(*stackb)->content = ((*stackb)->next)->content;
		(*stackb)->next->content = tmp;
	}
	ft_putendl_fd("ss", 1);
}
