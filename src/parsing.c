/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:11:16 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 12:45:03 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_ret	_is_numbers(char const *const input)
{
	size_t	i;

	i = 0;
	if (input[i] == '-')
		i++;
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (KO);
		i++;
	}
	return (OK);
}

static t_ret	_is_repeat(t_pile const *const pile, int const val)
{
	size_t	i;

	i = 0;
	while (i < pile->size)
	{
		if (pile->data[i] == val)
			return (OK);
		i++;
	}
	return (KO);
}

t_ret	parse_input(t_pile *const pile, char const *const *const input)
{
	size_t	i;
	int		num;

	i = 0;
	while (i < pile->capacity)
	{
		if (_is_numbers(input[i]))
		{
			num = ft_atoi(input[i]);
			if (_is_repeat(pile, num))
				return (KO);
			else
				pile_add_back(pile, num);
		}
		else
			return (KO);
		i++;
	}
	return (OK);
}
