/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:09:06 by alde-fre          #+#    #+#             */
/*   Updated: 2023/03/18 15:18:42 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"

t_context	*context_create(size_t const capacity)
{
	t_context	*context;

	context = malloc(sizeof(t_context));
	if (context == NULL)
		return (NULL);
	context->pile_a = pile_create(capacity);
	if (context->pile_a == NULL)
		return (free(context), NULL);
	context->pile_b = pile_create(capacity);
	if (context->pile_b == NULL)
		return (pile_destroy(context->pile_a), free(context), NULL);
	context->pile_t = pile_create(capacity);
	if (context->pile_t == NULL)
		return (pile_destroy(context->pile_a), pile_destroy(context->pile_b),
			free(context), NULL);
	return (context);
}

void	context_destroy(t_context *const context)
{
	pile_destroy(context->pile_t);
	pile_destroy(context->pile_b);
	pile_destroy(context->pile_a);
	free(context);
}

void	context_display(t_context *context)
{
	size_t	i;
	size_t	max;

	printf("┌────────────┐┌────────────┐\n");
	printf("│%-12s││%-12s│\n", "Pile A", "Pile B");
	printf("├────────────┤├────────────┤\n");
	max = context->pile_a->size;
	if (context->pile_b->size > context->pile_a->size)
		max = context->pile_b->size;
	i = 0;
	while (i < max + 1)
	{
		if (i < context->pile_a->size)
			printf("├%12d│", context->pile_a->data[i]);
		else if (i == context->pile_a->size)
			printf("└────────────┘");
		if (i > context->pile_a->size)
			printf("              ");
		if (i < context->pile_b->size)
			printf("├%12d│", context->pile_b->data[i]);
		else if (i == context->pile_b->size)
			printf("└────────────┘");
		printf("\n");
		i++;
	}
}
