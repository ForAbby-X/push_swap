/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:51:16 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/09 17:57:49 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "pile.h"

typedef struct s_context	t_context;

t_context	*context_create(size_t capacity);
void		context_destroy(t_context *context);
//void		context_display(t_context *context);

struct s_context
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_pile	*pile_t;
};

#endif
