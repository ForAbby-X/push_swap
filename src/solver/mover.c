/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:26:33 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/02 00:35:25 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

void	action_to_smallest(t_context *const context)
{
	t_minmax	minmax;

	minmax = get_minmax(context->pile_a);
	while (context->pile_a->data[0] != minmax.val_min)
	{
		if (minmax.index_min <= context->pile_a->size / 2)
			action_ra(context);
		else
			action_rra(context);
	}
}

void	action_push_cost(t_context *const context, t_cost cost)
{
	while (cost.a)
	{
		if (cost.a > 0)
			action_ra(context);
		else
			action_rra(context);
		if (cost.a > 0)
			cost.a--;
		else
			cost.a++;
	}
	while (cost.b)
	{
		if (cost.b > 0)
			action_rb(context);
		else
			action_rrb(context);
		if (cost.b > 0)
			cost.b--;
		else
			cost.b++;
	}
	action_pa(context);
}

void	extract_and_sort_b(t_context *const context)
{
	size_t		i;
	t_cost		min_cost;
	t_cost		cost;

	while (context->pile_b->size)
	{
		i = 0;
		min_cost.sum = INT_MAX;
		while (i < context->pile_b->size)
		{
			cost = get_cost(context, context->pile_b->data[i], i);
			if (ft_abs(cost.sum) < ft_abs(min_cost.sum))
				min_cost = cost;
			i++;
		}
		action_push_cost(context, min_cost);
	}
}

void	action_push_value(t_context *const context, size_t const index)
{
	int const	val = context->pile_a->data[index];

	while (context->pile_a->data[0] != val)
	{
		if (index < context->pile_a->size / 2)
			action_ra(context);
		else
			action_rra(context);
	}
	action_pb(context);
}
