/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:13:57 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/17 15:24:05 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_draw *draw, t_glob *glob)
{
	if (draw)
	{
		if (draw->z1 == 0 && draw->z2 == 0)
			return (0xFFFFFF);
	}
	if (glob->color == 0)
		return (0xFF9900);
	if (glob->color == 1)
		return (0xFF0000);
	if (glob->color == 2)
		return (0x660066);
	if (glob->color == 3)
		return (0x0000FF);
	if (glob->color == 4)
		return (0x00CC00);
	if (glob->color == 5)
		return (0x993300);
	else
		return (0);
}
