/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:56:59 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 14:23:35 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_pile	*pile_create(size_t const capacity)
{
	t_pile	*res;

	res = malloc(sizeof(t_pile));
	if (res == NULL)
		return (NULL);
	res->data = malloc(sizeof(int) * capacity);
	if (res->data == NULL)
		return (free(res), NULL);
	res->size = 0;
	res->capacity = capacity;
	return (res);
}

void	pile_destroy(t_pile *const pile)
{
	free(pile->data);
	pile->size = 0;
	pile->capacity = 0;
	free(pile);
}
