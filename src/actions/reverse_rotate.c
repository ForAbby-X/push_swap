/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:49:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/15 00:19:59 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	action_rra(t_context *const context)
{
	int		val;

	write(1, "rra\n", 4);
	if (context->pile_a->size < 2)
		return ;
	val = context->pile_a->data[context->pile_a->size - 1];
	pile_rem(context->pile_a, context->pile_a->size - 1);
	pile_add_front(context->pile_a, val);
}

void	action_rrb(t_context *const context)
{
	int		val;

	write(1, "rrb\n", 4);
	if (context->pile_b->size < 2)
		return ;
	val = context->pile_b->data[context->pile_b->size - 1];
	pile_rem(context->pile_b, context->pile_b->size - 1);
	pile_add_front(context->pile_b, val);
}

void	action_rrr(t_context *const context)
{
	int		val;

	write(1, "rrr\n", 4);
	if (context->pile_a->size >= 2)
	{
		val = context->pile_a->data[context->pile_a->size - 1];
		pile_rem(context->pile_a, context->pile_a->size - 1);
		pile_add_front(context->pile_a, val);
	}
	if (context->pile_b->size < 2)
		return ;
	val = context->pile_b->data[context->pile_b->size - 1];
	pile_rem(context->pile_b, context->pile_b->size - 1);
	pile_add_front(context->pile_b, val);
}
