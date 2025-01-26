/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:59 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/06 15:28:17 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*make_list(t_list **stack_a, int size)
{
	int		*list;
	int		i;
	t_list	*current;

	list = (int *)malloc(sizeof(int) * size + 1);
	if (!list)
		return (NULL);
	i = 0;
	current = *stack_a;
	while (current)
	{
		if (!current->content)
		{
			free(list);
			return (NULL);
		}
		list[i] = ft_atoi((char *)current->content);
		i++;
		current = current->next;
	}
	return (list);
}

static void	sort_list(int *list, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (list[j] < list[j - 1])
			{
				temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
			}
			j--;
		}
		i++;
	}
}

static int	assign_rank(t_list **stack_a, int *list, int size)
{
	t_list	*current;
	int		rank;
	char	*rank_str;

	rank = 0;
	while (rank < size)
	{
		current = *stack_a;
		while (current && list[rank] != ft_atoi((char *)current->content))
			current = current->next;
		if (!current)
			return (1);
		rank_str = ft_itoa(rank);
		if (!rank_str)
			return (1);
		free(current->content);
		current->content = rank_str;
		rank++;
	}
	return (0);
}

int	map_to_rank(t_list **stack_a)
{
	int	*list;
	int	size;

	if (!stack_a || !*stack_a)
		return (1);
	size = ft_lstsize(*stack_a);
	list = make_list(stack_a, size);
	if (!list)
		return (1);
	sort_list(list, size);
	if (assign_rank(stack_a, list, size))
	{
		free(list);
		return (1);
	}
	free(list);
	return (0);
}
