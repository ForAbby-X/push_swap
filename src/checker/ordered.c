/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:40:51 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/13 01:51:52 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ret	is_sorted(t_pile *const pile)
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
