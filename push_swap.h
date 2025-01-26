/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:49:25 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 18:19:51 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		check_sort(char **argv);
char	**check_arg(int argc, char **argv);
char	**format_arguments(char **argv);
char	**copy_argv(int argc, char **argv);
t_list	**create_stack(int argc, char **argv);
int		return_arraysize(char **array);
void	free_array(char **array);
void	free_stack(t_list **stack_a, t_list **stack_b);

int		sort(t_list **stack_a, t_list **stack_b, int argc);
int		sort_three(t_list **stack_a, t_list **stack_b, int argc);
int		sort_small(t_list **stack_a, t_list **stack_b);
int		sort_large(t_list **stack_a, t_list **stack_b, int argc);

int		get_max(t_list **stack);
int		get_min(t_list **stack);
int		get_a_position(t_list **stack, int target);
int		get_b_position(t_list **stack, int target);
int		map_to_rank(t_list **stack_a);
int		push_reference(t_list **stack_a, t_list **stack_b);
int		calculate_best_move(t_list **stack_a, t_list **stack_b, int size);
void	rotate_to_position(t_list **stack_a, t_list **stack_b, int a_pos,
			int b_pos);
void	rotate_to_position_a(t_list **stack_a, t_list **stack_b, int size,
			int pos);
void	rotate_to_position_b(t_list **stack_a, t_list **stack_b, int size,
			int pos);

void	push(t_list **stack_a, t_list **stack_b, char target);
void	rotate(t_list **stack_a, t_list **stack_b, char target);
void	reverse_rotate(t_list **stack_a, t_list **stack_b, char target);
void	swap(t_list **stack_a, t_list **stack_b, char target);

#endif
