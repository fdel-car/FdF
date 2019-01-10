/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:26:50 by fdel-car          #+#    #+#             */
/*   Updated: 2018/09/19 15:34:08 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if ((glob->fd = open(str, O_RDONLY)) == -1)
		return (0);
	data = ft_init(glob);
	if (!data)
		return (0);
	glob->x = ft_max_x(&data);
	glob->y_max = ft_max_y(&data);
	mlx_clear_window(glob->mlx, glob->win);
	glob->img = mlx_new_image(glob->mlx, glob->width, glob->height);
	glob->disp = mlx_get_data_addr(glob->img, &(glob->bpp),
	&(glob->sizeline), &(glob->endian));
	ft_draw_hor(&data, glob, draw);
	ft_draw_ver(&data, glob, draw, 0);
	ft_putstring(glob);
	glob->data = data;
	glob->draw = draw;
	glob->str = str;
	ft_free_data(&data);
	close(glob->fd);
	mlx_put_image_to_window(glob->mlx, glob->win, glob->img, 0, 0);
	mlx_destroy_image(glob->mlx, glob->img);
	return (1);
}
