/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_system.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:30:18 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/09 17:27:27 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_position_a(t_list **stack_a, t_list **stack_b, int size,
		int pos)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate(stack_a, stack_b, 'a');
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_rotate(stack_a, stack_b, 'a');
	}
}

void	rotate_to_position_b(t_list **stack_a, t_list **stack_b, int size,
		int pos)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate(stack_a, stack_b, 'b');
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_rotate(stack_a, stack_b, 'b');
	}
}

static void	rotate_system_1(t_list **stack_a, t_list **stack_b, int a_pos,
		int b_pos)
{
	if (a_pos >= b_pos)
	{
		a_pos -= b_pos;
		while (b_pos-- > 0)
			rotate(stack_a, stack_b, 'r');
		while (a_pos-- > 0)
			rotate(stack_a, stack_b, 'a');
	}
	else
	{
		b_pos -= a_pos;
		while (a_pos-- > 0)
			rotate(stack_a, stack_b, 'r');
		while (b_pos-- > 0)
			rotate(stack_a, stack_b, 'b');
	}
}

static void	rotate_system_2(t_list **stack_a, t_list **stack_b, int a_pos,
		int b_pos)
{
	if (a_pos >= b_pos)
	{
		a_pos -= b_pos;
		while (b_pos-- > 0)
			reverse_rotate(stack_a, stack_b, 'r');
		while (a_pos-- > 0)
			reverse_rotate(stack_a, stack_b, 'a');
	}
	else
	{
		b_pos -= a_pos;
		while (a_pos-- > 0)
			reverse_rotate(stack_a, stack_b, 'r');
		while (b_pos-- > 0)
			reverse_rotate(stack_a, stack_b, 'b');
	}
}

void	rotate_to_position(t_list **stack_a, t_list **stack_b, int a_pos,
		int b_pos)
{
	int	a_size;
	int	b_size;

	a_size = ft_lstsize(*stack_a);
	b_size = ft_lstsize(*stack_b);
	if (a_pos <= a_size / 2 && b_pos <= b_size / 2)
		rotate_system_1(stack_a, stack_b, a_pos, b_pos);
	else if (a_pos > a_size / 2 && b_pos > b_size / 2)
	{
		a_pos = a_size - a_pos;
		b_pos = b_size - b_pos;
		rotate_system_2(stack_a, stack_b, a_pos, b_pos);
	}
	else
	{
		rotate_to_position_a(stack_a, stack_b, a_size, a_pos);
		rotate_to_position_b(stack_a, stack_b, b_size, b_pos);
	}
}
