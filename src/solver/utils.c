/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:05:06 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 18:57:12 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

t_minmax	get_minmax(t_pile *const pile)
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

size_t	pile_get_dist(t_pile const *const pile, int val)
{
	size_t	index;

	index = pile_get_index(pile, val);
	if (index < pile->size / 2)
		return (index);
	else
		return (pile->size - index);
}

void	action_push_value(t_context *const context, int val)
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
	size_t	index;

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
	index = 0;
	while (!(val > pile->data[index % pile->size] \
		&& val < pile->data[(index + 1) % pile->size]))
		index++;
	if (index < pile->size / 2)
		return (index);
	else
		return (-(pile->size - index));
}

t_cost	get_cost(t_context *const context, int val)
{
	size_t	index;
	t_cost	cost;

	index = pile_get_index(context->pile_b, val);
	printf("here\n");
	cost.val = val;
	if (index < context->pile_b->size / 2)
		cost.b = index;
	else
		cost.b = -(context->pile_b->size - index);
	printf("there\n");
	cost.a = _get_cost_betw(context->pile_a, val);
	printf("but now ?\n");
	cost.sum = cost.a + cost.b;
	return (cost);
}
