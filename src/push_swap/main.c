/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:09:42 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/13 01:50:29 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "context.h"
#include "solver.h"

int	main(int const argc, char const *const *const argv)
{
	t_context	*context;

	if (argc <= 1)
		return (0);
	context = context_create(argc - 1);
	if (context == NULL)
		return (printf("Error\n"), 1);
	if (parse_input(context->pile_a, argv + 1) == KO)
		return (context_destroy(context), printf("Error\n"), 1);
	if (solver(context) == KO)
		return (context_destroy(context), printf("Error\n"), 1);
	context_destroy(context);
	return (0);
}
