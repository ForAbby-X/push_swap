/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:49:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/02 00:10:48 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	action_sa(t_context *const context)
{
	write(1, "sa\n", 3);
	if (context->pile_a->size >= 2)
		ft_swap(&context->pile_a->data[0], &context->pile_a->data[1]);
}

void	action_sb(t_context *const context)
{
	write(1, "sb\n", 3);
	if (context->pile_b->size >= 2)
		ft_swap(&context->pile_b->data[0], &context->pile_b->data[1]);
}

void	action_ss(t_context *const context)
{
	write(1, "ss\n", 3);
	if (context->pile_a->size >= 2)
		ft_swap(&context->pile_a->data[0], &context->pile_a->data[1]);
	if (context->pile_b->size >= 2)
		ft_swap(&context->pile_b->data[0], &context->pile_b->data[1]);
}
