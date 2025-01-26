/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:20:10 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/03 20:16:36 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_elements(t_list **stack_a, t_list **stack_b, int *nbrs)
{
	int	one;
	int	two;
	int	three;

	one = nbrs[0];
	two = nbrs[1];
	three = nbrs[2];
	if (one < two && one < three && two < three)
		return ;
	else if (one < two && one < three && two > three)
	{
		reverse_rotate(stack_a, stack_b, 'a');
		swap(stack_a, stack_b, 'a');
	}
	else if (one > two && one < three && two < three)
		swap(stack_a, stack_b, 'a');
	else if (one < two && one > three && two > three)
		reverse_rotate(stack_a, stack_b, 'a');
	else if (one > two && one > three && two < three)
		rotate(stack_a, stack_b, 'a');
	else if (one > two && one > three && two > three)
	{
		swap(stack_a, stack_b, 'a');
		reverse_rotate(stack_a, stack_b, 'a');
	}
}

int	sort_three(t_list **stack_a, t_list **stack_b, int argc)
{
	int		nbr[3];
	int		i;
	t_list	*current;

	i = 0;
	if (argc == 2)
	{
		if (!*stack_a || !(*stack_a)->next)
			return (1);
		if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content))
			swap(stack_a, stack_b, 'a');
		return (1);
	}
	current = *stack_a;
	while (i < 3)
	{
		if (!current)
			return (1);
		nbr[i] = ft_atoi(current->content);
		current = current->next;
		i++;
	}
	sort_elements(stack_a, stack_b, nbr);
	return (0);
}
