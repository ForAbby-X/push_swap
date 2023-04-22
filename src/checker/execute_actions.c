/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:51:43 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/16 04:47:16 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ret	execute_actions(t_context *const context)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (do_action(context, line) == KO)
			return (KO);
		free(line);
		line = get_next_line(0);
	}
	return (OK);
}
