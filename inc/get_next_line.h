/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:00:10 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/12 12:50:34 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(char const *str)
		__attribute__((always_inline));
char	*ft_strnchr(char *const str, char const c, size_t const n)
		__attribute__((always_inline));
void	*ft_memcpy(void *const dest, void const *const src,	size_t const size)
		__attribute__((always_inline));

char	*get_next_line(int fd);

#endif
