/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_reference.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:33:16 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 16:36:14 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_reference1(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b, 'b');
}

static void	push_reference2(t_list **stack_a, t_list **stack_b)
{
	int	num1;
	int	num2;

	push(stack_a, stack_b, 'b');
	num1 = ft_atoi((char *)(*stack_b)->content);
	num2 = ft_atoi((char *)(*stack_b)->next->content);
	if (num1 < num2)
		swap(stack_a, stack_b, 'b');
}

int	push_reference(t_list **stack_a, t_list **stack_b)
{
	push_reference1(stack_a, stack_b);
	push_reference2(stack_a, stack_b);
	return (0);
}
