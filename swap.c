/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:14:34 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/09 17:02:33 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_target(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	void	*temp;

	first = *stack;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void	swap(t_list **stack_a, t_list **stack_b, char target)
{
	if (target == 'a' && stack_a && *stack_a && (*stack_a)->next)
	{
		swap_target(stack_a);
		write(1, "sa\n", 3);
	}
	else if (target == 'b' && stack_b && *stack_b && (*stack_b)->next)
	{
		swap_target(stack_b);
		write(1, "sb\n", 3);
	}
	else if (target == 's' && stack_a && *stack_a && (*stack_a)->next && stack_b
		&& *stack_b && (*stack_b)->next)
	{
		swap_target(stack_a);
		swap_target(stack_b);
		write(1, "ss\n", 3);
	}
	else
		write(2, "Push Erro4\n", 11);
}
