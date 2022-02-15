/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:43:55 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/15 14:34:08 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	freeandquit(char **split_args)
{
	free_tab(split_args);
	quit();
}

void	add_to_list(int j, int i, long nbr, t_list **stack_a)
{
	if (j == 0 && i == 1)
		*stack_a = ft_lstnew((int)nbr);
	else
		ft_lstadd_back(stack_a, ft_lstnew((int)nbr));
}

void	one_arg_parsing(char *argv[], int i, long nbr, t_list **stack_a)
{
	int		j;
	char	**split_args;

	split_args = ft_split(argv[i], ' ');
	if (split_args[0] != NULL)
	{
		j = 0;
		while (split_args[j])
		{
			if (split_args[j][0] == '\0')
				exit(0);
			if (!str_is_digit(split_args[j])
				|| ft_strlen(split_args[j]) > 11)
				freeandquit(split_args);
			nbr = ft_atoi(split_args[j]);
			if (!(nbr >= INT_MIN && nbr <= INT_MAX))
				freeandquit(split_args);
			add_to_list(j, i, nbr, stack_a);
			j++;
		}
	}
	else
		quit();
	free_tab(split_args);
}

void	checkandparse(int i, char *argv[], t_list **stack_a)
{
	long	nbr;

	nbr = 0;
	if (str_is_digit(argv[i]))
	{
		if (!str_is_digit(argv[i]) || ft_strlen(argv[i]) > 11)
			quit();
		nbr = ft_atoi(argv[i]);
		if (!(nbr >= INT_MIN && nbr <= INT_MAX))
			quit();
		if (i == 1)
			*stack_a = ft_lstnew((int)nbr);
		else
			ft_lstadd_back(stack_a, ft_lstnew((int)nbr));
	}
	else
		one_arg_parsing(argv, i, nbr, stack_a);
}

t_list	*parsing(int argc, char *argv[])
{
	t_list	*stack_a;
	int		i;

	if (argv[1][0] == '\0')
		exit(0);
	checkandparse(1, argv, &stack_a);
	i = 2;
	if (argc > 2)
	{
		while (argv[i])
		{
			if (argv[i][0] == '\0')
				exit(0);
			checkandparse(i, argv, &stack_a);
			i++;
		}
	}
	return (stack_a);
}
