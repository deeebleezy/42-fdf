/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:45:22 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/20 15:15:41 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mapstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		mapstr[i] = f(i, s[i]);
	}
	mapstr[i] = '\0';
	return (mapstr);
}
