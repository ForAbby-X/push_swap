/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:43:42 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/13 02:21:30 by mcourtoi         ###   ########.fr       */
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
{"sa\n", &action_sa},
{"sb\n", &action_sb},
{"ss\n", &action_ss},
{"ra\n", &action_ra},
{"rb\n", &action_rb},
{"rr\n", &action_rr},
{"rra\n", &action_rra},
{"rrb\n", &action_rrb},
{"rrr\n", &action_rrr},
{"pa\n", &action_pa},
{"pb\n", &action_pb},
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

t_ret	do_action(t_context *const context, char const *const action)
{
	size_t	i;

	i = 0;
	while (g_action_tab[i].name)
	{
		if (_ft_strcmp(action, g_action_tab[i].name) == 0)
		{
			g_action_tab[i].func(context);
			return (OK);
		}
		i++;
	}
	return (KO);
}
