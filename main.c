/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:41:12 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 18:19:18 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**array;
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	array = check_arg(argc - 1, argv + 1);
	if (!array)
		return (1);
	if (check_sort(array) != 0)
		return (free_array(array), 0);
	argc = return_arraysize(array);
	stack_a = create_stack(argc, array);
	free_array(array);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (free_stack(stack_a, stack_b), write(2, "Error\n", 6), 1);
	*stack_b = NULL;
	if (sort(stack_a, stack_b, argc) == 1)
		return (free_stack(stack_a, stack_b), write(2, "Error\n", 6), 1);
	free_stack(stack_a, stack_b);
	return (0);
}
