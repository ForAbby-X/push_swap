/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:48:32 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 15:22:10 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	action_pa(t_context *const context)
{
	int	val;

	write(1, "pa\n", 3);
	if (context->pile_b->size == 0)
		return ;
	val = context->pile_b->data[0];
	pile_rem(context->pile_b, 0);
	pile_add_front(context->pile_a, val);
}

void	action_pb(t_context *const context)
{
	int	val;

	write(1, "pb\n", 3);
	if (context->pile_a->size == 0)
		return ;
	val = context->pile_a->data[0];
	pile_rem(context->pile_a, 0);
	pile_add_front(context->pile_b, val);
}
