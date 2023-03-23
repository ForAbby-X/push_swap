/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:33:34 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 16:39:19 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_ret	pile_is_in(t_pile const *const pile, int val)
{
	size_t	i;

	i = 0;
	while (i < pile->size)
	{
		if (pile->data[i] == val)
			return (OK);
		i++;
	}
	return (KO);
}
