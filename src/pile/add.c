/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:23:12 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 14:23:28 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_ret	pile_add_front(t_pile *const pile, int const val)
{
	size_t	i;

	if (pile->size >= pile->capacity)
		return (KO);
	i = pile->size;
	while (i > 0)
	{
		pile->data[i] = pile->data[i - 1];
		i--;
	}
	pile->data[0] = val;
	pile->size++;
	return (OK);
}


t_ret	pile_add_back(t_pile *const pile, int const val)
{
	if (pile->size >= pile->capacity)
		return (KO);
	pile->data[pile->size] = val;
	pile->size++;
	return (OK);
}
