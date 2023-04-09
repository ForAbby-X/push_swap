/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:05:06 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/09 23:18:42 by alde-fre         ###   ########.fr       */
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

static inline size_t	_get_a_index(t_pile *const pile, int const val)
{
	size_t		i;
	t_minmax	minmax;

	if (pile->size < 2)
		return (0);
	minmax = get_minmax(pile);
	if (val < minmax.val_min)
		return (minmax.index_min);
	if (val > minmax.val_max)
		return ((minmax.index_max + 1) % pile->size);
	i = minmax.index_min;
	while ((i % pile->size) != minmax.index_max)
	{
		if (val > pile->data[i % pile->size]
			&& val < pile->data[(i + 1) % pile->size])
			break ;
		i++;
	}
	return ((i + 1) % pile->size);
}

static inline t_move	_get_move_try(
	t_context const	*const context,
	size_t const index_a,
	size_t const index_b,
	int const flag)
{
	t_move	move;

	if (flag & 0b01)
		move.a = index_a;
	else
		move.a = -(context->pile_a->size - index_a);
	if (flag & 0b10)
		move.b = index_b;
	else
		move.b = -(context->pile_b->size - index_b);
	if ((move.a < 0 && move.b >= 0) || (move.a >= 0 && move.b < 0))
		move.sum = ft_abs(move.a) + ft_abs(move.b);
	else
		move.sum = ft_max(ft_abs(move.a), ft_abs(move.b));
	return (move);
}

t_move	get_move(
	t_context *const context,
	int val,
	size_t const index_b)
{
	size_t const	index_a = _get_a_index(context->pile_a, val);
	t_move			move;
	t_move			best_move;
	int				flag;

	flag = 0;
	best_move.sum = INT_MAX;
	while (flag < 4)
	{
		move = _get_move_try(context, index_a, index_b, flag);
		if (ft_abs(move.sum) < ft_abs(best_move.sum))
			best_move = move;
		flag++;
	}
	best_move.val = val;
	return (best_move);
}
