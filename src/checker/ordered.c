/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:40:51 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/22 12:23:22 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ret	is_sorted(t_pile const *const pile)
{
	size_t	i;

	i = 0;
	while (i + 1 < pile->size)
	{
		if (pile->data[i] > pile->data[i + 1])
			return (KO);
		i++;
	}
	return (OK);
}
