/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:40:37 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/15 13:36:36 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Delete and clear the memory of the list until the end of it				  */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		free((*lst));
		(*lst) = next;
	}
}
