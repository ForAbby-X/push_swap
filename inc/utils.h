/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:19:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/01 20:19:58 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include "return.h"

int		ft_atoi(char const *const input, int *err);
void	ft_swap(int *const a, int *const b)__attribute__((always_inline));
int		ft_min(int const a, int const b)__attribute__((always_inline));
int		ft_max(int const a, int const b)__attribute__((always_inline));
int		ft_abs(int const a)__attribute__((always_inline));

#endif
