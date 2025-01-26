/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:31:56 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/09 17:02:31 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_target(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	*stack = first->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
}

void	rotate(t_list **stack_a, t_list **stack_b, char target)
{
	if (target == 'a' && stack_a && *stack_a && (*stack_a)->next)
	{
		rotate_target(stack_a);
		write(1, "ra\n", 3);
	}
	else if (target == 'b' && stack_b && *stack_b && (*stack_b)->next)
	{
		rotate_target(stack_b);
		write(1, "rb\n", 3);
	}
	else if (target == 'r' && stack_a && stack_b && *stack_a && *stack_b
		&& (*stack_a)->next && (*stack_b)->next)
	{
		rotate_target(stack_a);
		rotate_target(stack_b);
		write(1, "rr\n", 3);
	}
	else
		write(2, "Push Erro3\n", 11);
}
