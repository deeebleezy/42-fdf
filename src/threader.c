/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:55:24 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:27:07 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*threader(void *v)
{
	t_view	*view;

	view = (t_view*)v;
	draw_lines(view->m, view->y, view->y_lim);
	return ((void*)view);
}
