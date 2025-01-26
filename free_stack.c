/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:08:30 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/06 15:34:59 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
	{
		if (*stack_a)
			ft_lstclear(stack_a, free);
		free(stack_a);
	}
	if (stack_b)
	{
		if (*stack_b)
			ft_lstclear(stack_b, free);
		free(stack_b);
	}
}
