/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:26:44 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/29 17:07:37 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static t_ret	_lis_recurs(t_pile const *const input, t_pile *const output
	, size_t i, t_pile *const sub)
{
	while (i < input->size)
	{
		if (input->data[i] > sub->data[sub->size - 1])
		{
			pile_add_back(sub, input->data[i]);
			if (_lis_recurs(input, output, i + 1, sub) == KO)
				return (KO);
		}
		i++;
	}
	if (output->size <= sub->size)
		if (pile_copy_data(output, sub) == KO)
			return (KO);
	if (pile_rem_last(sub) == KO)
		return (KO);
	return (OK);
}

/* Return a pile of the longest increasing subsequence in input */
static inline t_pile	*_get_lis(t_pile const *const input)
{
	t_pile	*sub;
	t_pile	*out;

	sub = pile_create(input->capacity);
	if (sub == NULL)
		return (NULL);
	out = pile_create(input->capacity);
	if (out == NULL)
		return (pile_destroy(sub), pile_destroy(out), NULL);
	if (pile_add_back(sub, input->data[0])
		&& _lis_recurs(input, out, 0, sub) == KO)
		return (pile_destroy(sub), pile_destroy(out), NULL);
	return (pile_destroy(sub), out);
}

static inline void	_rotate_to_smallest(t_pile *const pile)
{
	t_minmax	minmax;

	minmax = get_minmax(pile);
	while (pile->data[0] != minmax.val_min)
		pile_rotate(pile);
}

static inline void	_extract_lis(t_context *const context, t_pile *const lis)
{
	size_t	i;
	size_t	min_cost;
	size_t	min_index;
	size_t	cost;

	while (context->pile_a->size > lis->size)
	{
		i = -1;
		min_cost = ULONG_MAX;
		min_index = 0;
		while (++i < context->pile_a->size)
		{
			if (pile_is_in(lis, context->pile_a->data[i]))
				continue ;
			cost = pile_get_dist(context->pile_a, context->pile_a->data[i]);
			if (cost < min_cost)
			{
				min_index = i;
				min_cost = cost;
			}
		}
		action_push_value(context, context->pile_a->data[min_index]);
	}
}

static inline void	action_push_cost(t_context *const context, t_cost cost)
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

static inline void	_extract_and_sort_b(t_context *const context)
{
	size_t	i;
	t_cost	min_cost;
	t_cost	cost;

	while (context->pile_b->size)
	{
		i = 0;
		min_cost.sum = INT_MAX;
		while (i < context->pile_b->size)
		{
			cost = get_cost(context, context->pile_b->data[i]);
			if (ft_abs(cost.sum) < ft_abs(min_cost.sum))
				min_cost = cost;
			i++;
		}
		action_push_cost(context, min_cost);
		//context_display(context);
	}
}

t_ret	solver(t_context *const context)
{
	t_pile	*lis;

	//context_display(context);
	if (pile_copy_data(context->pile_t, context->pile_a) == KO)
		return (KO);
	_rotate_to_smallest(context->pile_t);
	lis = _get_lis(context->pile_t);
	if (lis == NULL)
		return (KO);
	//pile_display(lis, "lis");
	_extract_lis(context, lis);
	_extract_and_sort_b(context);
	_rotate_to_smallest(context->pile_a);
	//context_display(context);
	pile_destroy(lis);
	return (OK);
}
