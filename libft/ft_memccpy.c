/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:30:55 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/19 20:40:56 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	bytes;

	bytes = 0;
	while (bytes < n)
	{
		*((unsigned char *)s1 + bytes) = *((unsigned char *)s2 + bytes);
		if (*((unsigned char *)s2 + bytes) == (unsigned char)c)
			return ((unsigned char *)s1 + bytes + 1);
		bytes++;
	}
	return (NULL);
}
