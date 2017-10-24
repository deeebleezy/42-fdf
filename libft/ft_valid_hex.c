/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:54:02 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/09/26 13:55:30 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_valid_hex(char *s)
{
	if (ft_strlen(s) > 10 || ft_strncmp(s, "0x", 2))
		return (0);
	++s;
	while (*(++s))
		if (!ft_isalnum(*s))
			return (0);
	return (1);
}
