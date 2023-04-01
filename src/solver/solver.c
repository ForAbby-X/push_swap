/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:26:44 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/02 01:10:52 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static t_ret	_lis_recurs(t_pile const *const input, t_pile *const output
	, size_t i, t_pile *const sub)
{
	if (sub->size < output->size)
		return (pile_rem_last(sub));
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
	if (output->size <= sub->size && pile_copy_data(output, sub) == KO)
		return (KO);
	return (pile_rem_last(sub));
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
		return (pile_destroy(sub), NULL);
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

static inline void	_extract_lis(
	t_context *const context,
	t_pile const *const lis)
{
	size_t	i;

	i = 0;
	while (context->pile_a->size > lis->size)
	{
		if (pile_is_in(lis, context->pile_a->data[i]) == KO)
		{
			action_push_value(context, i);
			i = 0;
		}
		else
			i++;
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
	//pile_display(lis, "Lis");
	_extract_lis(context, lis);
	//context_display(context);
	extract_and_sort_b(context);
	action_to_smallest(context);
	//context_display(context);
	pile_destroy(lis);
	return (OK);
}
