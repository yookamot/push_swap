/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:24:21 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 17:30:50 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**copy_argv(int argc, char **argv)
{
	int		i;
	char	**array;

	i = 0;
	array = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!array)
		return (NULL);
	while (i < argc)
	{
		array[i] = ft_strdup(argv[i]);
		if (!array[i])
			return (free_array(array), NULL);
		i++;
	}
	array[i] = NULL;
	return (array);
}
