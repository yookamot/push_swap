/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_arraysize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:54:02 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 18:00:00 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_arraysize(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}
