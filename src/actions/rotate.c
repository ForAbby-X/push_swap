/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:49:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 15:57:29 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	action_ra(t_context *const context)
{
	write(1, "ra\n", 3);
	pile_rotate(context->pile_a);
}

void	action_rb(t_context *const context)
{
	write(1, "ra\n", 3);
	pile_rotate(context->pile_b);
}

void	action_rr(t_context *const context)
{
	write(1, "rr\n", 3);
	pile_rotate(context->pile_a);
	pile_rotate(context->pile_b);
}
