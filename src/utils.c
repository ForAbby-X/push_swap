/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:19:44 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 15:33:22 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(char const *const input)
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
		ret = ret * 10 + (input[i] - '0');
		i++;
	}
	return (ret * sign);
}

void	ft_swap(int *const a, int *const b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_max(int const a, int const b)
{
	if (a > b)
		return (a);
	return (b);
}
