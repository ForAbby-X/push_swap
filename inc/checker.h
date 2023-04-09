/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:41:06 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/09 23:10:49 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "actions.h"

t_ret	is_sorted(t_pile *const pile);
void	do_action(t_context *const context, char const *const action);
void	d(t_context *const context, char const *const action);

#endif
