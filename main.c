/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:27:18 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/05 00:09:49 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft/includes/libft.h"
#include <stdlib.h>

void	ft_draw_hor(t_data **data, t_glob *glob, t_draw *draw)
{
	t_data	*temp;
	int		i;

	i = 1;
	temp = *data;
	while (temp->next)
	{
		draw->x1 = ft_iso(temp->x, temp->y, 0);
		draw->y1 = ft_iso(temp->x, temp->y, 1);
		draw->z1 = temp->z;
		draw->x2 = ft_iso((temp->next)->x, (temp->next)->y, 0);
		draw->y2 = ft_iso((temp->next)->x, (temp->next)->y, 1);
		draw->z2 = (temp->next)->z;
		ft_draw_line(draw, glob, 0xFFFFFF);
		temp = temp->next;
		if (i == glob->x && temp->next)
		{
			temp = temp->next;
			i = 0;
		}
		i++;
	}
}

int		ft_max_x(t_data **data)
{
	t_data	*temp;
	int		x;

	x = 0;
	temp = *data;
	while (temp)
	{
		if (temp->x > x)
			x = temp->x;
		temp = temp->next;
	}
	return (x);
}

int		main(int ac, char **av)
{
	t_data	*data;
	t_draw	*draw;
	t_glob	glob;

	draw = (t_draw*)malloc(sizeof(t_draw));
	glob.mlx = mlx_init();
	glob.win = mlx_new_window(glob.mlx, WIDTH, HEIGHT, "fdf");
	if (ac == 2)
	{
		data = ft_init(av[1]);
		glob.x = ft_max_x(&data);
		ft_draw_hor(&data, &glob, draw);
	}
	mlx_loop(glob.mlx);
	return (0);
}
