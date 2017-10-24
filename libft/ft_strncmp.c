/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:15:41 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/20 10:44:29 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*r1;
	unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	while ((*r1 && *r2) && n)
	{
		if (*r1 != *r2)
			return (*r1 - *r2);
		r1++;
		r2++;
		n--;
	}
	if (n)
		return (*r1 - *r2);
	return (0);
}
