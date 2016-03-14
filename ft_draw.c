/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:29:41 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/13 20:51:24 by fdel-car         ###   ########.fr       */
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

void	ft_draw_line(t_draw *dr, t_glob *glob, unsigned int color)
{
	dr->dx = ft_abs(dr->x2 - dr->x1);
	dr->dy = ft_abs(dr->y2 - dr->y1);
	dr->sx = dr->x1 < dr->x2 ? 1 : -1;
	dr->sy = dr->y1 < dr->y2 ? 1 : -1;
	dr->err = (dr->dx < dr->dy ? dr->dx : -dr->dy) / 2;
	mlx_pixel_put(glob->mlx, glob->win, dr->x1, dr->y1 + 1, color);
	while (1)
	{
		if ((dr->sx == 1 && dr->x1 > dr->x2) || (dr->sx == -1 &&
			dr->x1 < dr->x2) || (dr->x1 == dr->x2 && dr->y1 == dr->y2))
			break ;
		dr->e2 = dr->err;
		if (dr->e2 > -dr->dx)
		{
			dr->err -= dr->dy;
			dr->x1 += dr->sx;
		}
		if (dr->e2 < dr->dy)
		{
			dr->err += dr->dx;
			dr->y1 += dr->sy;
		}
		mlx_pixel_put(glob->mlx, glob->win, dr->x1, dr->y1, color);
	}
}
