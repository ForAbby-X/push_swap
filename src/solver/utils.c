/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:05:06 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/29 17:06:09 by alde-fre         ###   ########.fr       */
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

size_t	pile_get_dist(t_pile const *const pile, int const val)
{
	size_t	index;

	index = pile_get_index(pile, val);
	if (index < pile->size / 2)
		return (index);
	else
		return (pile->size - index);
}

void	action_push_value(t_context *const context, int const val)
{
	size_t	index;	

	index = pile_get_index(context->pile_a, val);
	while (context->pile_a->data[0] != val)
	{
		if (index < context->pile_a->size / 2)
			action_ra(context);
		else
			action_rra(context);
	}
	action_pb(context);
}

static inline int	_get_cost_betw(t_pile *const pile, int val)
{
	size_t		i;
	t_minmax	minmax;

	if (pile->size < 2)
		return (0);
	if (pile->size == 2)
	{
		if (pile->data[0] < val && pile->data[1] > val)
			return (1);
		else if (pile->data[1] < val && pile->data[0] > val)
			return (-1);
		else
			return (0);
	}
	minmax = get_minmax(pile);
	if (val < minmax.val_min)
		return (pile_get_dist(pile, minmax.val_min));
	if (val > minmax.val_max)
		return (pile_get_dist(pile, minmax.val_max) + 1);
	i = minmax.index_min;
	while ((i % pile->size) != minmax.index_max)
	{
		if (val > pile->data[i % pile->size] && val < pile->data[(i + 1) % pile->size])
			break ;
		i++;
	}
	i = (i + 1) % pile->size;
	if (i < pile->size / 2)
		return (i);
	else
		return (-(pile->size - i));
}

t_cost	get_cost(t_context *const context, int val)
{
	size_t	index;
	t_cost	cost;

	index = pile_get_index(context->pile_b, val);
	cost.val = val;
	if (index < context->pile_b->size / 2)
		cost.b = index;
	else
		cost.b = -(context->pile_b->size - index);
	cost.a = _get_cost_betw(context->pile_a, val);
	cost.sum = cost.a + cost.b;
	return (cost);
}
