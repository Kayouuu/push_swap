/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:15:35 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/14 10:00:51 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	quit(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	ft_putnbr(int n)
{
	char	c;
	long	nb;

	nb = (long)n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr((nb / 10));
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 1;
	if (!(str[0] == '-' || ft_isdigit(str[0])))
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && i != 0)
			return (0);
		i++;
	}
	return (1);
}

t_list	*parsing(int argc, char *argv[])
{
	t_list	*stacka;
	int		i;
	long	nbr;

	i = 2;
	if (!str_is_digit(argv[1]))
		quit();
	nbr = ft_atoi(argv[1]);
	if (!(nbr >= INT_MIN && nbr <= INT_MAX))
		quit();
	stacka = ft_lstnew((int)nbr);
	while (argc > i)
	{
		if (!str_is_digit(argv[i]))
		{
			ft_lstclear(&stacka);
			free(stacka);
			quit();
		}
		nbr = ft_atoi(argv[i]);
		if (!(nbr >= INT_MIN && nbr <= INT_MAX))
		{
			ft_lstclear(&stacka);
			free(stacka);
			quit();
		}
		ft_lstadd_back(&stacka, ft_lstnew((int)nbr));
		i++;
	}
	return (stacka);
}

int	main(int argc, char *argv[])
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	if (argc > 2)
		stacka = parsing(argc, argv);
	else
		quit();
	if (ft_is_sorted(stacka))
	{
		ft_lstclear(&stacka);
		free(stacka);
		exit(0);
	}
	ft_lstiter(stacka, ft_putnbr);
	write(1, "\n", 1);
	which_case(&stacka, &stackb);
	ft_putendl_fd("", 1);
	ft_lstiter(stacka, ft_putnbr);
	ft_lstclear(&stacka);
	ft_lstclear(&stackb);
}
