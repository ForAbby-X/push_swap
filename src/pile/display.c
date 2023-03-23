/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:38:04 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/23 13:42:09 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	pile_display(t_pile const *const pile, char const *const name)
{
	size_t	i;

	printf("┌────────────┐\n");
	printf("│%-12s│\n", name);
	printf("├────────────┤\n");
	i = 0;
	while (i < pile->size)
	{
		printf("├%12d│\n", pile->data[i]);
		i++;
	}
	printf("└────────────┘\n");
}
