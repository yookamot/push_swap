/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:35:53 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/10 22:05:15 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list **stack)
{
	t_list	*current;
	int		max;
	int		num;

	current = *stack;
	max = INT_MIN;
	while (current)
	{
		num = ft_atoi(current->content);
		if (num > max)
			max = num;
		current = current->next;
	}
	return (max);
}

int	get_min(t_list **stack)
{
	t_list	*current;
	int		min;
	int		num;

	current = *stack;
	min = INT_MAX;
	while (current)
	{
		num = ft_atoi(current->content);
		if (num < min)
			min = num;
		current = current->next;
	}
	return (min);
}

int	get_a_position(t_list **stack, int target)
{
	t_list	*current;
	int		pos;
	int		num;

	pos = 0;
	current = *stack;
	while (current)
	{
		num = ft_atoi(current->content);
		if (num == target)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

static int	get_limit_position(t_list **stack_b, int best)
{
	int	min;
	int	max;
	int	pos;

	min = get_min(stack_b);
	max = get_max(stack_b);
	if (best < min)
		return (get_a_position(stack_b, min) + 1);
	else if (best > max)
	{
		pos = get_a_position(stack_b, max);
		if (pos == 0)
			return (ft_lstsize(*stack_b));
		else
			return (pos);
	}
	else
		return (-1);
}

int	get_b_position(t_list **stack_b, int best)
{
	t_list	*current;
	t_list	*last;
	int		pos;

	last = ft_lstlast(*stack_b);
	if (best > ft_atoi((char *)((*stack_b)->content))
		&& best < ft_atoi((char *)(last->content)))
		return (0);
	current = *stack_b;
	pos = 1;
	while (current && current->next)
	{
		if (best < ft_atoi((char *)(current->content))
			&& best > ft_atoi((char *)(current->next->content)))
			return (pos);
		current = current->next;
		pos++;
	}
	return (get_limit_position(stack_b, best));
}
