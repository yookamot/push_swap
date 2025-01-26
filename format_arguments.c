/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:04:48 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 18:06:35 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**format_arguments(char **argv)
{
	char	*trimmed;
	char	**array;

	trimmed = ft_strtrim(argv[0], "\"");
	if (!trimmed)
		return (NULL);
	array = ft_split(trimmed, ' ');
	free(trimmed);
	return (array);
}
