/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:10:20 by yookamot          #+#    #+#             */
/*   Updated: 2025/01/11 18:19:35 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atol(const char *str)
{
	long long	result;
	int			sign;
	int			digit;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		digit = *str - '0';
		if (sign == 1 && (result > LLONG_MAX / 10 || (result == LLONG_MAX / 10
					&& digit > LLONG_MAX % 10)))
			return (LLONG_MAX);
		if (sign == -1 && (result > -(LLONG_MIN / 10) || (result == -(LLONG_MIN
						/ 10) && digit > -(LLONG_MIN % 10))))
			return (LLONG_MIN);
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

static int	check_num(char **argv)
{
	int			i;
	int			j;
	long long	value;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		value = ft_atol(argv[i]);
		if (value < (long long)INT_MIN || value > (long long)INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicate(char **argv)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (argv[i + 1])
	{
		j = i + 1;
		num = ft_atoi(argv[i]);
		while (argv[j])
		{
			if (num == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sort(char **argv)
{
	int	size;
	int	num1;
	int	num2;
	int	i;

	size = return_arraysize(argv);
	i = 0;
	while (size-- > 1)
	{
		num1 = ft_atoi(argv[i]);
		num2 = ft_atoi(argv[i + 1]);
		if (num1 > num2)
			return (0);
		i++;
	}
	return (1);
}

char	**check_arg(int argc, char **argv)
{
	char	**array;

	if (argc == 0)
		return (NULL);
	else if (argc == 1)
	{
		array = format_arguments(argv);
		if (!array)
			return (NULL);
	}
	else
	{
		array = copy_argv(argc, argv);
		if (!array)
			return (NULL);
	}
	if (check_num(array) != 0 || check_duplicate(array) != 0)
		return (write(2, "Error\n", 6), free_array(array), NULL);
	return (array);
}
