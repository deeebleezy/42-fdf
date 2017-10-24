/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_inc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:15:00 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 19:53:51 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_inc(int col_1, int col_2, int level)
{
	int r;
	int g;
	int b;

	if (!level)
		return (col_1);
	r = (((col_1 & 0xFF0000) - (col_2 & 0xFF0000)) >> 16) / 10 * level;
	g = (((col_1 & 0x00FF00) - (col_2 & 0x00FF00)) >> 8) / 10 * level;
	b = ((col_1 & 0x0000FF) - (col_2 & 0x0000FF)) / 10 * level;
	return (((col_1 >> 16) - r) << 16 | (((col_1 & 0xff00) >> 8) - g)
			<< 8 | (col_1 & 0xff) - b);
}
