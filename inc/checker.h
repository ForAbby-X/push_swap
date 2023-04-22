/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:41:06 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/22 12:23:08 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "actions.h"
# include "parsing.h"
# include "get_next_line.h"

t_ret	is_sorted(t_pile const *const pile);
t_ret	do_action(t_context *const context, char const *const action);
t_ret	execute_actions(t_context *const context);

#endif
