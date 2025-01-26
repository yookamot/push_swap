/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_best_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:31:38 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 01:15:51 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_a_move(t_list **stack_a, int num)
{
	int		count;
	int		size;
	t_list	*current;

	count = 0;
	size = ft_lstsize(*stack_a);
	current = *stack_a;
	while (ft_atoi((char *)current->content) != num)
	{
		count++;
		current = current->next;
	}
	if (count > size / 2)
		count = -(size - count);
	return (count);
}

static int	calculate_b_move(t_list **stack_b, int num)
{
	t_list	*last;
	int		count;
	int		size;
	t_list	*current;

	last = ft_lstlast(*stack_b);
	if (num > ft_atoi((char *)((*stack_b)->content))
		&& num < ft_atoi((char *)(last->content)))
		return (0);
	count = 1;
	size = ft_lstsize(*stack_b);
	current = *stack_b;
	while (current && current->next)
	{
		if (num < ft_atoi((char *)(current->content))
			&& num > ft_atoi((char *)(current->next->content)))
			break ;
		count++;
		current = current->next;
	}
	if (count > size / 2)
		count = -(size - count);
	return (count);
}

static int	calculate_move_count(t_list **stack_a, t_list **stack_b, int num)
{
	int	a_move;
	int	b_move;

	a_move = calculate_a_move(stack_a, num);
	b_move = calculate_b_move(stack_b, num);
	if (a_move >= 0 && b_move >= 0)
	{
		if (a_move >= b_move)
			return (a_move);
		else
			return (b_move);
	}
	else if (a_move < 0 && b_move < 0)
	{
		if (a_move <= b_move)
			return (-a_move);
		else
			return (-b_move);
	}
	else if (a_move >= 0 && b_move < 0)
		return (a_move - b_move);
	else
		return (-a_move + b_move);
}

int	calculate_best_move(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*current;
	int		move_count;
	int		num;
	int		best_move_count;
	int		best;

	current = *stack_a;
	best_move_count = INT_MAX;
	while (size-- > 0)
	{
		num = ft_atoi((char *)current->content);
		move_count = calculate_move_count(stack_a, stack_b, num);
		if (move_count < best_move_count)
		{
			best_move_count = move_count;
			best = num;
		}
		current = current->next;
	}
	return (best);
}
