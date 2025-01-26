/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:28:34 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/10 19:30:55 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**create_stack(int argc, char **argv)
{
	int		i;
	t_list	**stack;
	t_list	*new_node;
	char	*num;

	i = 0;
	stack = (t_list **)malloc(sizeof(t_list *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	while (i < argc)
	{
		num = ft_strdup(argv[i]);
		if (!num)
			return (ft_lstclear(stack, free), NULL);
		new_node = ft_lstnew(num);
		if (!new_node)
			return (free(num), ft_lstclear(stack, free), NULL);
		ft_lstadd_back(stack, new_node);
		i++;
	}
	return (stack);
}
