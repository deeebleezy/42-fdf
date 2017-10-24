/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:14:37 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 14:45:43 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	compute_code(double x, double y)
{
	int code;

	code = 0;
	if (x < 0)
		code |= 1;
	if (x > WIN_WIDTH - 1)
		code |= 2;
	if (y < 0)
		code |= 4;
	if (y > WIN_HEIGHT - 1)
		code |= 8;
	return (code);
}
