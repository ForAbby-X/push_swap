/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:09:24 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/29 16:44:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "return.h"
# include "actions.h"
# include "context.h"
# include "utils.h"
# include <limits.h>

typedef struct s_minmax	t_minmax;

typedef struct s_cost	t_cost;

/* Returns the smallest and the biggest value */
/* of a pile along with their indexes.		  */
t_minmax	get_minmax(t_pile const *const pile);

size_t		pile_get_dist(t_pile const *const pile, int const val);
void		action_push_value(t_context *const context, int const val);
t_cost		get_cost(t_context *const context, int val);

/* Solves the push swap problem. */
t_ret		solver(t_context *const context);

struct s_minmax
{
	size_t	index_min;
	int		val_min;
	size_t	index_max;
	int		val_max;
};

struct s_cost
{
	int		a;
	int		b;
	int		sum;
	int		val;
};

#endif
