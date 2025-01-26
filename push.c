/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:03:09 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/09 17:02:22 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_target(t_list **stack_1, t_list **stack_2)
{
	t_list	*first;

	if (!stack_2 || !*stack_2)
		return ;
	first = *stack_2;
	*stack_2 = (*stack_2)->next;
	ft_lstadd_front(stack_1, first);
}

void	push(t_list **stack_a, t_list **stack_b, char target)
{
	if (target == 'a')
	{
		push_target(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	else if (target == 'b')
	{
		push_target(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
	else
		write(2, "Push Erro1\n", 11);
}
