/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:16:00 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 15:03:34 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H

# include <stdlib.h>
# include "return.h"

# include <unistd.h>
# include <stdio.h>

typedef struct s_pile	t_pile;

t_pile	*pile_create(size_t const capacity);
void	pile_destroy(t_pile *const pile);

t_ret	pile_add_front(t_pile *const pile, int const val);
t_ret	pile_add_back(t_pile *const pile, int const val);

t_ret	pile_rem(t_pile *const pile, size_t const index);
t_ret	pile_rem_last(t_pile *const pile);
t_ret	pile_clear(t_pile *const pile);

struct s_pile
{
	int		*data;
	size_t	size;
	size_t	capacity;
};

#endif
