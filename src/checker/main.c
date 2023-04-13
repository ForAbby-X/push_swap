/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:54:08 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/13 02:18:43 by mcourtoi         ###   ########.fr       */
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
		return (printf("Error\n"), 1);
	if (parse_input(context->pile_a, argv + 1) == KO)
		return (context_destroy(context), printf("Error parse\n"), 1);
	if (execute_actions(context) == KO)
		return (context_destroy(context), printf("Error exec\n"), 1);
	if (is_sorted(context->pile_a) == KO || context->pile_b->size != 0)
		return (printf("KO\n"), 1);
	context_destroy(context);
	return (printf("OK\n"), 0);
}
