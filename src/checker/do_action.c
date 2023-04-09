/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:43:42 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/09 23:10:45 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

typedef struct s_builtin	t_builtin;
typedef void				(*t_funcptr)(t_context *const context);

struct s_builtin
{
	char const *const	name;
	t_funcptr const		func;
};

static t_builtin const	g_action_tab[] = {
{"sa", &action_sa},
{"sb", &action_sb},
{"ss", &action_ss},
{"ra", &action_ra},
{"rb", &action_rb},
{"rr", &action_rr},
{"rra", &action_rra},
{"rrb", &action_rrb},
{"rrr", &action_rrr},
{"pa", &action_pa},
{"pb", &action_pb},
{NULL, NULL}
};

static inline int	_ft_strcmp(char const *str0, char const *str1)
{
	while (*str0 && *str0 == *str1)
	{
		++str0;
		++str1;
	}
	return (*str0 - *str1);
}

void	do_action(t_context *const context, char const *const action)
{
	size_t	i;

	i = 0;
	while (g_action_tab[i].name)
	{
		if (_ft_strcmp(action, g_action_tab[i].name) == 0)
		{
			g_action_tab[i].func(context);
			return ;
		}
		i++;
	}
}
