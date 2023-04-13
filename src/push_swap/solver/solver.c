/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:26:44 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/13 02:23:40 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static t_pile	*_generate_sub(
	t_pile const *const in)
{
	t_pile *const	out = pile_create(in->size);
	size_t			i;
	size_t			j;

	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < in->size)
	{
		pile_add_back(out, 1);
		j = 0;
		while (j < i)
		{
			if (in->data[i] > in->data[j] && out->data[j] + 1 > out->data[i])
				out->data[i] = out->data[j] + 1;
			j++;
		}
		i++;
	}
	return (out);
}

/* Return a pile of the longest increasing subsequence in input */
static inline t_pile	*_get_lis(t_pile const *const input)
{
	t_pile		*sub;
	t_pile		*lis;
	t_minmax	minmax;
	size_t		size;
	int			i;

	sub = _generate_sub(input);
	minmax = get_minmax(sub);
	lis = pile_create(minmax.val_max);
	if (lis == NULL)
		return (pile_destroy(sub), NULL);
	size = input->size;
	i = minmax.val_max;
	while (lis->size < lis->capacity)
		pile_add_back(lis, 0);
	while (size-- > 0)
	{
		if (sub->data[size] == i)
		{
			lis->data[i - 1] = input->data[size];
			i--;
		}
	}
	return (pile_destroy(sub), lis);
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
			action_push_index(context, i);
			i = 0;
		}
		else
			i++;
	}
}

t_ret	solver(t_context *const context)
{
	t_pile	*lis;

	if (is_sorted(context->pile_a) == OK)
		return (OK);
	if (context->pile_a->size == 2)
		return (action_sa(context), OK);
	if (context->pile_a->size == 3)
		return (solve_3(context), OK);
	if (pile_copy_data(context->pile_t, context->pile_a) == KO)
		return (KO);
	_rotate_to_smallest(context->pile_t);
	lis = _get_lis(context->pile_t);
	if (lis == NULL)
		return (KO);
	_extract_lis(context, lis);
	extract_and_sort_b(context);
	pile_destroy(lis);
	action_to_smallest(context);
	return (OK);
}
