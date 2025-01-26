/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:43:50 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/09 17:02:26 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_target(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rotate(t_list **stack_a, t_list **stack_b, char target)
{
	if (target == 'a' && stack_a && *stack_a && (*stack_a)->next)
	{
		reverse_rotate_target(stack_a);
		write(1, "rra\n", 4);
	}
	else if (target == 'b' && stack_b && *stack_b && (*stack_b)->next)
	{
		reverse_rotate_target(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (target == 'r' && stack_a && *stack_a && (*stack_a)->next && stack_b
		&& *stack_b && (*stack_b)->next)
	{
		reverse_rotate_target(stack_a);
		reverse_rotate_target(stack_b);
		write(1, "rrr\n", 4);
	}
	else
		write(2, "Push Erro2\n", 11);
}
