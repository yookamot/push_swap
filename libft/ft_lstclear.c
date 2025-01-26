/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 04:25:30 by yookamot          #+#    #+#             */
/*   Updated: 2024/12/15 18:10:18 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*x;
	t_list	*y;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	x = *lst;
	while (x)
	{
		y = x->next;
		if (x->content)
			del(x->content);
		free(x);
		x = y;
	}
	*lst = NULL;
}
