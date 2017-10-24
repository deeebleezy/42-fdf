/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:11:00 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 14:48:46 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			first_step(t_m *m, char *arg)
{
	char	*buf;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd > 0)
		while (ft_get_next_line(fd, &buf))
			if (!parse_data(m, buf))
				return (0);
	close(fd);
	return (build_grid(m) ? 1 : 0);
}
