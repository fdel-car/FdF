/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:29:41 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/17 15:14:02 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	pixel_put(t_glob *glob, int x, int y, unsigned int color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if (x >= glob->width || y >= glob->height || x < 0 || y < 0)
		return ;
	glob->stat = 1;
	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	b = (color & 0xFF);
	glob->disp[y * glob->sizeline + x * glob->bpp / 8] = b;
	glob->disp[y * glob->sizeline + x * glob->bpp / 8 + 1] = g;
	glob->disp[y * glob->sizeline + x * glob->bpp / 8 + 2] = r;
}

int		ft_check(t_draw *dr)
{
	if ((dr->sx == 1 && dr->x1 > dr->x2) || (dr->sx == -1 &&
		dr->x1 < dr->x2) || (dr->x1 == dr->x2 && dr->y1 == dr->y2))
		return (0);
	return (1);
}

void	ft_draw_line(t_draw *dr, t_glob *glob, unsigned int color)
{
	dr->dx = ft_abs(dr->x2 - dr->x1);
	dr->dy = ft_abs(dr->y2 - dr->y1);
	dr->sx = dr->x1 < dr->x2 ? 1 : -1;
	dr->sy = dr->y1 < dr->y2 ? 1 : -1;
	dr->err = (dr->dx < dr->dy ? dr->dx : -dr->dy) / 2;
	pixel_put(glob, dr->x1, dr->y1 + 1, color);
	while (1)
	{
		if (!ft_check(dr))
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
		if (!ft_check(dr))
			break ;
		pixel_put(glob, dr->x1, dr->y1, color);
	}
}
