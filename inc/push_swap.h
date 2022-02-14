/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:07 by psaulnie          #+#    #+#             */
/*   Updated: 2022/02/14 17:07:12 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*	MAIN.C	*/

void	quit(void);

/*	SWAP.C				*/

void	sa(t_list **stacka);
void	sb(t_list **stackb);
void	ss(t_list **stacka, t_list **stackb);

/*	PUSH.C				*/

void	pa(t_list **stacka, t_list **stackb);
void	pb(t_list **stacka, t_list **stackb);

/*	ROTATE.C			*/

void	ra(t_list **stacka);
void	rb(t_list **stackb);
void	rr(t_list **stacka, t_list **stackb);

/*	REVERSE_ROTATE.C	*/

void	rra(t_list **stacka);
void	rrb(t_list **stackb);
void	rrr(t_list **stacka, t_list **stackb);

/*	CASE.C	*/

void	which_case(t_list **stack_a, t_list **stack_b);
void	case_three(t_list **stack_a);
void	case_five(t_list **stack_a, t_list **stack_b);

/*	RADIX.C	*/

int		get_max_digits(t_list *stack_a);
void	radix(t_list **stack_a, t_list **stack_b);

/*	UTILS.C	*/

void	clearandquit(t_list **stacka);
void	indexage(t_list **stack_a);
int		ft_is_sorted(t_list *stack);

#endif