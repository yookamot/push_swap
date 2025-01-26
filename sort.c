/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:27:14 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/07 21:35:37 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc <= 3)
	{
		if (sort_three(stack_a, stack_b, argc) == 1)
			return (1);
	}
	else if (argc <= 5)
	{
		if (sort_small(stack_a, stack_b) == 1)
			return (1);
	}
	else
	{
		if (sort_large(stack_a, stack_b, argc) == 1)
			return (1);
	}
	return (0);
}
