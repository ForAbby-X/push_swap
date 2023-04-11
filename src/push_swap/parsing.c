/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:11:16 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/01 19:24:58 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static inline t_ret	_is_numbers(char const *const input)
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

static inline t_ret	_is_repeat(t_pile const *const pile, int const val)
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
	int		err;

	i = 0;
	err = 0;
	while (i < pile->capacity)
	{
		if (_is_numbers(input[i]))
		{
			num = ft_atoi(input[i], &err);
			if (_is_repeat(pile, num) || err == KO)
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
