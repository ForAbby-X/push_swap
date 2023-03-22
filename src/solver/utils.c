/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 05:05:06 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 15:18:44 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

t_minmax	get_minmax(t_pile *const pile)
{
	size_t		i;
	t_minmax	minmax;

	i = 1;
	minmax.index_min = 0;
	minmax.index_max = 0;
	minmax.val_min = pile->data[0];
	minmax.val_max = pile->data[0];
	while (i < pile->size)
	{
		if (pile->data[i] < minmax.val_min)
		{
			minmax.index_min = i;
			minmax.val_min = pile->data[i];
		}
		if (pile->data[i] > minmax.val_max)
		{
			minmax.index_max = i;
			minmax.val_max = pile->data[i];
		}
		i++;
	}
	return (minmax);
}
