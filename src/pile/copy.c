/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:56:59 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 13:29:09 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_ret	pile_copy_data(t_pile *const dst, t_pile const *const src)
{
	size_t	i;

	pile_clear(dst);
	i = 0;
	while (i < src->size)
	{
		if (pile_add_back(dst, src->data[i]) == KO)
			return (KO);
		i++;
	}
	return (OK);
}
