/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:26:50 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/14 18:03:03 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fdf(t_draw *draw, t_glob *glob, t_data *data, char *str)
{
	data = ft_init(str);
	if (!data)
		return (0);
	glob->x = ft_max_x(&data);
	glob->y_max = ft_max_y(&data);
	ft_draw_hor(&data, glob, draw);
	ft_draw_ver(&data, glob, draw, 0);
	glob->data = data;
	glob->draw = draw;
	glob->str = str;
	return (1);
}
