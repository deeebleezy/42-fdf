/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:11:13 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:31:00 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			parse_data(t_m *m, char *buf)
{
	char	**line;

	if (!(line = ft_strsplit(buf, ' ')))
		return (0);
	if (!m->x_count)
		m->x_count = (double)ft_arrsize((void**)line);
	++m->y_count;
	if (ft_arrsize((void**)line) != m->x_count || !add_node(m, line))
		return (0);
	free_dbl(line, m->x_count);
	return (1);
}
