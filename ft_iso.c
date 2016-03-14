/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 23:42:15 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/14 21:09:49 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_iso_y(int x, int y, int z, t_glob *glob)
{
	int i;

	i = (x + y) * glob->zoom + HEIGHT / 4 - z + glob->move_y;
	return (i);
}

int		ft_iso_x(int x, int y, t_glob *glob)
{
	int i;

	i = (x - y) * glob->zoom * 2 + WIDTH / 2 + glob->move_x;
	return (i);
}
