/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:04:54 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/22 14:34:06 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int		words;

	while (*s && *s == c)
		s++;
	words = ((*s) ? 1 : 0);
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			words++;
		s++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	*start;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	if (!(result = (char **)malloc(sizeof(char *)
				* (count_words((char *)s, c) + 1))))
		return (NULL);
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(result++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		++s;
	}
	if (start != s)
		*(result++) = ft_strsub(start, 0, s - start);
	*result = NULL;
	return (result - words);
}
