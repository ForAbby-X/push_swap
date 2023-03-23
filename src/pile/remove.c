/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:23:38 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 13:22:36 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_ret	pile_rem(t_pile *const pile, size_t const index)
{
	size_t	i;

	if (index >= pile->size)
		return (KO);
	i = index;
	while (i + 1 < pile->size)
	{
		pile->data[i] = pile->data[i + 1];
		i++;
	}
	pile->size--;
	return (OK);
}

t_ret	pile_rem_last(t_pile *const pile)
{
	if (pile->size == 0)
		return (KO);
	pile->size--;
	return (OK);
}

void	pile_clear(t_pile *const pile)
{
	pile->size = 0LU;
}
