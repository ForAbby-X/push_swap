/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:05:06 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/02 00:41:29 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

t_minmax	get_minmax(t_pile const *const pile)
{
	size_t		i;
	t_minmax	minmax;

	i = 1;
	minmax.index_min = 0;
	minmax.index_max = 0;
	minmax.val_min = pile->data[0];
	minmax.val_max = pile->data[0];
	while (i < pile->size)
	{
		if (pile->data[i] < minmax.val_min)
		{
			minmax.index_min = i;
			minmax.val_min = pile->data[i];
		}
		if (pile->data[i] > minmax.val_max)
		{
			minmax.index_max = i;
			minmax.val_max = pile->data[i];
		}
		i++;
	}
	return (minmax);
}

long	pile_get_dist(t_pile const *const pile, size_t const index)
{
	if (index <= pile->size / 2)
		return (index);
	else
		return (-(pile->size - index));
}

static inline int	_get_cost_betw(t_pile *const pile,	int const val)
{
	size_t		i;
	t_minmax	minmax;

	if (pile->size < 2)
		return (0);
	minmax = get_minmax(pile);
	if (val < minmax.val_min)
		return (pile_get_dist(pile, minmax.index_min));
	if (val > minmax.val_max)
		return (pile_get_dist(pile, (minmax.index_max + 1) % pile->size));
	i = minmax.index_min;
	while ((i % pile->size) != minmax.index_max)
	{
		if (val > pile->data[i % pile->size]
			&& val < pile->data[(i + 1) % pile->size])
			break ;
		i++;
	}
	return (pile_get_dist(pile, (i + 1) % pile->size));
}

t_cost	get_cost(
	t_context *const context,
	int val,
	size_t const index)
{
	t_cost		cost;

	cost.val = val;
	if (index <= context->pile_b->size / 2)
		cost.b = index;
	else
		cost.b = -(context->pile_b->size - index);
	cost.a = _get_cost_betw(context->pile_a, val);
	cost.sum = cost.a + cost.b;
	return (cost);
}
