/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:27:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/14 17:44:03 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fdf.h"

int		ft_key(int keycode, t_glob *glob)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 71)
	{
		mlx_clear_window(glob->mlx, glob->win);
		ft_fdf(glob->draw, glob, glob->data, glob->str);
	}
	return(0);
}
