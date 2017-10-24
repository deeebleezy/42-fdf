/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 21:16:31 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/11 16:47:22 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	cur;

	cur = 0;
	while (src[cur] != '\0' && cur < n)
	{
		dest[cur] = src[cur];
		cur++;
	}
	while (cur < n)
	{
		dest[cur] = '\0';
		cur++;
	}
	return (dest);
}
