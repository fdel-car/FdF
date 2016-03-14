/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:26:50 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/14 21:36:05 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_free_data(t_data **data)
{
	t_data *temp;
	t_data *temp2;

	temp = *data;
	temp2 = NULL;
	while (temp->next)
	{
		if (temp2)
			temp = temp2;
		temp2 = temp->next;
		free(temp);
	}
}

int		ft_fdf(t_draw *draw, t_glob *glob, t_data *data, char *str)
{
	glob->y = 0;
	glob->fd = open(str, O_RDONLY);
	data = ft_init(glob);
	if (!data)
		return (0);
	glob->x = ft_max_x(&data);
	glob->y_max = ft_max_y(&data);
	ft_draw_hor(&data, glob, draw);
	ft_draw_ver(&data, glob, draw, 0);
	glob->data = data;
	glob->draw = draw;
	glob->str = str;
	ft_free_data(&data);
	close(glob->fd);
	return (1);
}
