/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:19:44 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/01 19:11:18 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(char const *const input, int *err)
{
	size_t	i;
	int		sign;
	int		ret;

	i = 0;
	sign = 1;
	if (input[i] == '-')
	{
		sign = -1;
		i++;
	}
	ret = 0;
	while (input[i] >= '0' && input[i] <= '9')
	{
		if ((int)(ret * 10 + (input[i] - '0') - (sign == -1)) < 0)
			return (*err = KO, 0);
		ret = ret * 10 + (input[i] - '0');
		i++;
	}
	return (*err = OK, ret * sign);
}

void	ft_swap(int *const a, int *const b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_min(int const a, int const b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int const a, int const b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int const a)
{
	if (a < 0)
		return (-a);
	return (a);
}
