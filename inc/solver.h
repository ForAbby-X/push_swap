/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:09:24 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/12 11:31:04 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "return.h"
# include "actions.h"
# include "context.h"
# include "utils.h"
# include "checker.h"
# include <limits.h>

typedef struct s_minmax	t_minmax;

typedef struct s_move	t_move;

/* Returns the smallest and the biggest value */
/* of a pile along with their indexes.		  */
t_minmax	get_minmax(t_pile const *const pile);

void		action_push_index(t_context *const context, size_t const index)
			__attribute__((always_inline));
t_move		get_move(t_context *const context, int val, size_t const i)
			__attribute__((always_inline));

void		action_to_smallest(t_context *const context)
			__attribute__((always_inline));
void		action_push_move(t_context *const context, t_move *const move)
			__attribute__((always_inline));
void		extract_and_sort_b(t_context *const context);

/* Solves the push swap problem. */
t_ret		solver(t_context *const context);

void		solve_3(t_context *const context);

struct s_minmax
{
	size_t	index_min;
	int		val_min;
	size_t	index_max;
	int		val_max;
};

struct s_move
{
	long	a;
	long	b;
	size_t	cost;
	int		val;
};

#endif
