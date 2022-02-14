/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:12:10 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/14 10:01:04 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterate on the list and apply the function f on each element of the list   */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst)
	{
		(*f)(lst->content);
		ft_putstr_fd(" | ", 1);
		lst = lst->next;
	}
}
