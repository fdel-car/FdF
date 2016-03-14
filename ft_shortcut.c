/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:27:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/14 21:10:40 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fdf.h"

int		ft_unload_bis(int keycode, t_glob *glob)
{
	if (keycode == 0)
	{
		mlx_clear_window(glob->mlx, glob->win);
		glob->move_x -= 10;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 1)
	{
		mlx_clear_window(glob->mlx, glob->win);
		glob->move_y += 10;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 13)
	{
		mlx_clear_window(glob->mlx, glob->win);
		glob->move_y -= 10;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 69)
	{
		mlx_clear_window(glob->mlx, glob->win);
		glob->inc++;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	return (0);
}

int		ft_unload(int keycode, t_glob *glob)
{
	if (keycode == 126 && glob->zoom <= 64)
	{
		mlx_clear_window(glob->mlx, glob->win);
		glob->zoom = glob->zoom * 2;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 125 && glob->zoom > 1)
	{
		mlx_clear_window(glob->mlx, glob->win);
		glob->zoom = glob->zoom / 2;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 2)
	{
		mlx_clear_window(glob->mlx, glob->win);
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
		mlx_clear_window(glob->mlx, glob->win);
		glob->inc = 0;
		glob->move_x = 0;
		glob->move_y = 0;
		glob->zoom = 16;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	if (keycode == 78)
	{
		mlx_clear_window(glob->mlx, glob->win);
		glob->inc--;
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	else
		ft_unload(keycode, glob);
	return (0);
}
