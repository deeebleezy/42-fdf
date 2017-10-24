/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:46:19 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 14:42:24 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	add_node(t_m *m, char **line)
{
	t_line	*node;
	t_line	*ptr;
	int		i;

	i = -1;
	if (!(node = (t_line *)ft_memalloc(sizeof(t_line))))
		return (0);
	node->next = NULL;
	if (!(node->info = (char **)ft_memalloc(sizeof(char *) * m->x_count)))
		return (0);
	while (line[++i])
		if (!(node->info[i] = ft_strdup(line[i])))
			return (0);
	if (!m->line)
		m->line = node;
	else
	{
		ptr = m->line;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = node;
	}
	return (1);
}
