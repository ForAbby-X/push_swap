/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:16:35 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/22 13:36:14 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

void	solve_3(t_context *const context)
{
	t_pile const *const	a = context->pile_a;

	if (is_sorted(a))
		return ;
	if (a->data[0] > a->data[1] && a->data[0] < a->data[2])
		action_sa(context);
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		action_sa(context);
		action_rra(context);
	}
	else if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
		action_ra(context);
	else if (a->data[0] < a->data[1] && a->data[0] < a->data[2])
	{
		action_sa(context);
		action_ra(context);
	}
	else if (a->data[0] < a->data[1] && a->data[0] > a->data[2])
		action_rra(context);
}

void	solve_5(t_context *const context)
{
	while (context->pile_a->size > 3)
		action_push_index(context, get_minmax(context->pile_a).index_min);
	solve_3(context);
	while (context->pile_b->size)
		action_pa(context);
}
