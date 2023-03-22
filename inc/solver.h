/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:09:24 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 15:29:13 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "return.h"
# include "actions.h"
# include "context.h"
# include <limits.h>

typedef struct s_minmax	t_minmax;

/* Returns the smallest and the biggest value */
/* of a pile along with their indexes.		  */
t_minmax	get_minmax(t_pile *const pile);

/* Solves the push swap problem. */
t_ret		solver(t_context *const context);

struct s_minmax
{
	size_t	index_min;
	int		val_min;
	size_t	index_max;
	int		val_max;
};

#endif
