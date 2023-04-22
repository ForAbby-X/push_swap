/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:37:43 by alde-fre          #+#    #+#             */
/*   Updated: 2023/04/22 13:13:37 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	char const *const	start = str;

	while (*str)
		str++;
	return (str - start);
}

char	*ft_strnchr(char *const str, char const c, size_t const n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(
	void *const dest,
	void const *const src,
	size_t size)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	while (size--)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	return (dest);
}
