/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:15:35 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/15 14:17:12 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	quit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_putnbr(int n)
{
	char	c;
	long	nb;

	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, 1);
	c = nb % 10 + '0';
	write(1, &c, 1);
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
	if (ft_lstsize(stacka) == 1 || ft_is_sorted(stacka))
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
