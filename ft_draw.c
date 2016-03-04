/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:29:41 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/04 19:02:14 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft/includes/libft.h"

int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	ft_draw_line(t_draw *draw, t_glob *glob, unsigned int color)
{
	draw->dx = ft_abs(draw->x2 - draw->x1);
	draw->dy = ft_abs(draw->y2 - draw->y1);
	draw->sx = draw->x1 < draw->x2 ? 1 : -1;
	draw->sy = draw->y1 < draw->y2 ? 1 : -1;
	draw->err = (draw->dx < draw->dy ? draw->dx : -draw->dy) / 2;
	while (1)
	{
		mlx_pixel_put(glob->mlx, glob->win, draw->x1, draw->y1, color);
		if ((draw->sx == 1 && draw->x1 > draw->x2) ||
			(draw->sx == -1 && draw->x1 < draw->x2) ||
			(draw->x1 == draw->x2 && draw->y1 == draw->y2))
			break ;
		draw->e2 = draw->err;
		if (draw->e2 > -draw->dx)
		{
			draw->err -= draw->dy;
			draw->x1 += draw->sx;
		}
		if (draw->e2 < draw->dy)
		{
			draw->err += draw->dx;
			draw->y1 += draw->sy;
		}
	}
}
