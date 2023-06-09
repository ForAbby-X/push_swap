/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:54:08 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/09 19:57:23 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int const argc, char const *const *const argv)
{
	t_context	*context;

	if (argc <= 1)
		return (0);
	context = context_create(argc - 1);
	if (context == NULL)
		return (write(1, "Error\n", 6), 1);
	if (parse_input(context->pile_a, argv + 1) == KO)
		return (context_destroy(context), write(1, "Error\n", 6), 1);
	if (is_sorted(context->pile_a) == KO && execute_actions(context) == KO)
		return (context_destroy(context), write(1, "Error\n", 6), 1);
	if (context->pile_b->size != 0 || is_sorted(context->pile_a) == KO)
		return (context_destroy(context), write(1, "KO\n", 3), 1);
	context_destroy(context);
	return (write(1, "OK\n", 3), 0);
}
