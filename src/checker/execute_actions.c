/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:51:43 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/04/13 02:18:56 by mcourtoi         ###   ########.fr       */
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
