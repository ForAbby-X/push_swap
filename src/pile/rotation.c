/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:54:08 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 15:58:26 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	pile_rotate(t_pile *const pile)
{
	int		val;

	if (pile->size < 2)
		return ;
	val = pile->data[0];
	pile_rem(pile, 0);
	pile_add_back(pile, val);
}

void	pile_rrotate(t_pile *const pile)
{
	int		val;

	if (pile->size < 2)
		return ;
	val = pile->data[pile->size - 1];
	pile_rem(pile, pile->size - 1);
	pile_add_front(pile, val);
}
