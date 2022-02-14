/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:26:12 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/12 15:42:39 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Delete an element of the list with a pointer fonction					  */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
