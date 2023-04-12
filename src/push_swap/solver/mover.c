/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:26:33 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/12 11:30:42 by alde-fre         ###   ########.fr       */
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

static inline void	action_push_same(
	t_context *const context,
	t_move *const move)
{
	while (move->a > 0 && move->b > 0)
	{
		action_rr(context);
		move->a--;
		move->b--;
	}
	while (move->a < 0 && move->b < 0)
	{
		action_rrr(context);
		move->a++;
		move->b++;
	}
}

void	action_push_move(t_context *const context, t_move *const move)
{
	action_push_same(context, move);
	while (move->a)
	{
		if (move->a > 0)
			action_ra(context);
		else
			action_rra(context);
		move->a -= ft_norm(move->a);
	}
	while (move->b)
	{
		if (move->b > 0)
			action_rb(context);
		else
			action_rrb(context);
		move->b -= ft_norm(move->b);
	}
	action_pa(context);
}

void	extract_and_sort_b(t_context *const context)
{
	size_t		i;
	t_move		min_move;
	t_move		move;

	while (context->pile_b->size)
	{
		i = 0;
		min_move.cost = INT_MAX;
		while (i < context->pile_b->size)
		{
			move = get_move(context, context->pile_b->data[i], i);
			if (move.cost < min_move.cost)
				min_move = move;
			i++;
		}
		action_push_move(context, &min_move);
	}
}

void	action_push_index(t_context *const context, size_t const index)
{
	int const	val = context->pile_a->data[index];

	while (context->pile_a->data[0] != val)
	{
		if (index <= context->pile_a->size / 2)
			action_ra(context);
		else
			action_rra(context);
	}
	action_pb(context);
}
