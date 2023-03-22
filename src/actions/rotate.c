/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:49:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/15 05:34:53 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	action_ra(t_context *const context)
{
	int		val;

	write(1, "ra\n", 3);
	if (context->pile_a->size < 2)
		return ;
	val = context->pile_a->data[0];
	pile_rem(context->pile_a, 0);
	pile_add_back(context->pile_a, val);
}

void	action_rb(t_context *const context)
{
	int		val;

	write(1, "rb\n", 3);
	if (context->pile_b->size < 2)
		return ;
	val = context->pile_b->data[0];
	pile_rem(context->pile_b, 0);
	pile_add_back(context->pile_b, val);
}

void	action_rr(t_context *const context)
{
	int		val;

	write(1, "rr\n", 3);
	if (context->pile_a->size >= 2)
	{
		val = context->pile_a->data[0];
		pile_rem(context->pile_a, 0);
		pile_add_back(context->pile_a, val);
	}
	if (context->pile_b->size < 2)
		return ;
	val = context->pile_b->data[0];
	pile_rem(context->pile_b, 0);
	pile_add_back(context->pile_b, val);
}
