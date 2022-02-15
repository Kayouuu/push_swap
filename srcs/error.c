/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:12:55 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/15 14:17:58 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 1;
	if (!(str[0] == '-' || ft_isdigit(str[0]))
		|| (str[0] == '-' && ft_isdigit(str[1]) == 0))
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && i != 0)
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_list *stack_a)
{
	t_list	*start;
	t_list	*secondary;
	int		i;
	int		has_duplicate;

	has_duplicate = 0;
	start = stack_a;
	while (stack_a->next != NULL)
	{
		secondary = stack_a->next;
		i = 0;
		while (i != ft_lstsize(start) - 1)
		{
			if (secondary->content == stack_a->content)
				has_duplicate = 1;
			if (secondary->next == NULL)
				secondary = start;
			else
				secondary = secondary->next;
			i++;
		}
		stack_a = stack_a->next;
	}
	stack_a = start;
	return (has_duplicate);
}
