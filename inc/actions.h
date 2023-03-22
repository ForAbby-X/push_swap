/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:11:38 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 14:38:23 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "context.h"
# include "unistd.h"
# include "utils.h"

void	action_pa(t_context *const context);
void	action_pb(t_context *const context);

void	action_sa(t_context *const context);
void	action_sb(t_context *const context);
void	action_ss(t_context *const context);

void	action_ra(t_context *const context);
void	action_rb(t_context *const context);
void	action_rr(t_context *const context);

void	action_rra(t_context *const context);
void	action_rrb(t_context *const context);
void	action_rrr(t_context *const context);

#endif
