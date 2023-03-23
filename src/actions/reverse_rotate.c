/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:49:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 16:04:41 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	action_rra(t_context *const context)
{
	write(1, "rra\n", 4);
	pile_rrotate(context->pile_a);
}

void	action_rrb(t_context *const context)
{
	write(1, "rrb\n", 4);
	pile_rrotate(context->pile_b);
}

void	action_rrr(t_context *const context)
{
	write(1, "rrr\n", 4);
	pile_rrotate(context->pile_a);
	pile_rrotate(context->pile_b);
}
