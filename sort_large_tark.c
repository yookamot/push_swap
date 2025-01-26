/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_tark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:04:19 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 20:02:46 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_large(t_list **stack_a, t_list **stack_b, int argc)
{
	int	best;
	int	a_pos;
	int	b_pos;
	int	max;

	if (!stack_a || !*stack_a || map_to_rank(stack_a) != 0
		|| push_reference(stack_a, stack_b) != 0)
		return (1);
	max = argc - 1;
	while (argc-- > 3)
	{
		best = calculate_best_move(stack_a, stack_b, ft_lstsize(*stack_a));
		a_pos = get_a_position(stack_a, best);
		b_pos = get_b_position(stack_b, best);
		rotate_to_position(stack_a, stack_b, a_pos, b_pos);
		push(stack_a, stack_b, 'b');
	}
	b_pos = get_b_position(stack_b, ft_atoi((char *)(*stack_a)->content));
	rotate_to_position_b(stack_a, stack_b, ft_lstsize(*stack_b), b_pos);
	push(stack_a, stack_b, 'b');
	rotate_to_position_b(stack_a, stack_b, ft_lstsize(*stack_b),
		get_a_position(stack_b, max));
	while (*stack_b)
		push(stack_a, stack_b, 'a');
	return (0);
}
