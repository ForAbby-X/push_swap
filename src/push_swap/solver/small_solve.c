/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:16:35 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/09 22:16:17 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

void	solve_3(t_context *const context)
{
	t_pile const *const	a = context->pile_a;

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
