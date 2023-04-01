/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:09:24 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/01 22:38:48 by alde-fre         ###   ########.fr       */
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

long		pile_get_dist(t_pile const *const pile, size_t const index);
void		action_push_value(t_context *const context, size_t const index)
			__attribute__((always_inline));
t_cost		get_cost(t_context *const context, int val, size_t const i);

void		action_to_smallest(t_context *const context)
			__attribute__((always_inline));
void		action_push_cost(t_context *const context, t_cost cost);
void		extract_and_sort_b(t_context *const context);

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
