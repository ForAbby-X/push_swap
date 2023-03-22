/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:26:44 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 15:51:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static int	_lis(t_pile const *const input, t_pile *const output)
{
	size_t			i;
	size_t			j;
	t_pile *const	sub = pile_create(input->capacity);

	if (sub == NULL)
		return (KO);
	i = 1;
	while (i < input->size)
	{
		j = i;
		pile_clear(output);
		pile_add_front(output, input->data[0]);
		while (j < input->size)
		{
			if ()
			j++;
		}
		i++;
	}
}

static void	_rotate_to_smallest(t_context *const context)
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

t_ret	solver(t_context *const context)
{
	context_display(context);
	_rotate_to_smallest(context);
	printf("LIS IS :%d\n", _recurs_lis(context->pile_a, 0, context->pile_a->size, INT_MIN));
	context_display(context);
	return (OK);
}
