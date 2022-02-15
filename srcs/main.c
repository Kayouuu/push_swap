/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:15:35 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/15 09:44:34 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	quit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
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

t_list	*parsing(int argc, char *argv[])
{
	t_list	*stacka;
	int		i;
	long	nbr;

	i = 1;
	if (argv[1][0] == '\0')
		exit(0);
	if (!str_is_digit(argv[1]) || ft_strlen(argv[1]) > 11)
		quit();
	nbr = ft_atoi(argv[1]);
	if (!(nbr >= INT_MIN && nbr <= INT_MAX))
		quit();
	stacka = ft_lstnew((int)nbr);
	while (argc > ++i)
	{
		if (argv[i][0] == '\0')
			exit(0);
		if (!str_is_digit(argv[i]) || ft_strlen(argv[1]) > 11)
			clearandquit(&stacka);
		nbr = ft_atoi(argv[i]);
		if (!(nbr >= INT_MIN && nbr <= INT_MAX))
			clearandquit(&stacka);
		ft_lstadd_back(&stacka, ft_lstnew((int)nbr));
	}
	return (stacka);
}

int	main(int argc, char *argv[])
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	if (argc > 1)
		stacka = parsing(argc, argv);
	else
		exit(0);
	if (ft_is_sorted(stacka))
	{
		ft_lstclear(&stacka);
		exit(0);
	}
	indexage(&stacka);
	if (has_duplicate(stacka) == 1)
	{
		ft_lstclear(&stacka);
		quit();
	}
	which_case(&stacka, &stackb);
	ft_lstclear(&stacka);
	ft_lstclear(&stackb);
}
