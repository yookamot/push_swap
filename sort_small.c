/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:29:06 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/09 16:50:17 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_small(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	min;
	int	pos;

	max = get_max(stack_a);
	pos = get_a_position(stack_a, max);
	rotate_to_position_a(stack_a, stack_b, ft_lstsize(*stack_a), pos);
	push(stack_a, stack_b, 'b');
	min = get_min(stack_a);
	pos = get_a_position(stack_a, min);
	rotate_to_position_a(stack_a, stack_b, ft_lstsize(*stack_a), pos);
	push(stack_a, stack_b, 'b');
	sort_three(stack_a, stack_b, ft_lstsize(*stack_a));
	push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
	rotate(stack_a, stack_b, 'a');
	return (0);
}
