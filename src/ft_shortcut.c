/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:27:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/16 21:25:07 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fdf.h"

int		ft_helper(int keycode, t_glob *glob)
{
	if (keycode == 4)
	{
		if (glob->help == 0)
		{
			glob->height -= 200;
			glob->help = 1;
			ft_fdf(glob->draw, glob, glob->data, glob->str);
		}
		else
		{
			glob->height += 200;
			glob->help = 0;
			ft_fdf(glob->draw, glob, glob->data, glob->str);
		}
	}
	return (0);
}

int		ft_changecolor(int keycode, t_glob *glob)
{
	if (keycode == 124)
	{
		glob->color += 1;
		if (glob->color == 6)
			glob->color = 0;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 123)
	{
		glob->color -= 1;
		if (glob->color == -1)
			glob->color = 5;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 69)
	{
		glob->inc++;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	else
		ft_helper(keycode, glob);
	return (0);
}

int		ft_unload_bis(int keycode, t_glob *glob)
{
	if (keycode == 0)
	{
		glob->move_x -= 10;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 1)
	{
		glob->move_y += 10;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 13)
	{
		glob->move_y -= 10;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	else
		ft_changecolor(keycode, glob);
	return (0);
}

int		ft_unload(int keycode, t_glob *glob)
{
	if (keycode == 126 && glob->zoom <= 64)
	{
		glob->zoom = glob->zoom * 2;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 125 && glob->zoom > 1)
	{
		glob->zoom = glob->zoom / 2;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 2)
	{
		glob->move_x += 10;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	else
		ft_unload_bis(keycode, glob);
	return (0);
}

int		ft_key(int keycode, t_glob *glob)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 71)
	{
		glob->inc = 1;
		glob->move_x = 0;
		glob->move_y = 0;
		glob->color = 0;
		glob->zoom = 16;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 78)
	{
		glob->inc--;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	else
		ft_unload(keycode, glob);
	return (0);
}
