/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:03:04 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/20 15:43:24 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			tmp;

	ptr = (unsigned char*)str;
	tmp = 0;
	while (tmp < len)
	{
		ptr[tmp] = (unsigned char)c;
		tmp++;
	}
	return (ptr);
}
