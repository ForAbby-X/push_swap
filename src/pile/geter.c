/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:39:32 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 16:55:34 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

size_t	pile_get_index(t_pile const *const pile, int val)
{
	size_t	i;

	i = 0;
	while (i < pile->size && pile->data[i] != val)
		i++;
	return (i);
}
