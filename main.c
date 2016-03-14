/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:27:18 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/14 21:50:47 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft/includes/libft.h"
#include <stdlib.h>

void	ft_draw_ver(t_data **data, t_glob *glob, t_draw *draw, int i)
{
	t_data	*temp;
	t_data	*temp2;
	int		j;
	int		k;

	temp2 = *data;
	while (i++ <= glob->x)
	{
		temp = temp2;
		k = 0;
		while (k++ < glob->y_max)
		{
			j = 0;
			draw->x1 = ft_iso_x(temp->x, temp->y, glob);
			draw->y1 = ft_iso_y(temp->x, temp->y, temp->z, glob);
			draw->z1 = temp->z;
			while (j++ <= glob->x)
				temp = temp->next;
			draw->x2 = ft_iso_x(temp->x, temp->y, glob);
			draw->y2 = ft_iso_y(temp->x, temp->y, temp->z, glob);
			draw->z2 = temp->z;
			ft_draw_line(draw, glob, ft_color(draw));
		}
		temp2 = temp2->next;
	}
}

void	ft_draw_hor(t_data **data, t_glob *glob, t_draw *draw)
{
	t_data	*temp;
	int		i;

	i = 1;
	temp = *data;
	while (temp->next)
	{
		draw->x1 = ft_iso_x(temp->x, temp->y, glob);
		draw->y1 = ft_iso_y(temp->x, temp->y, temp->z, glob);
		draw->z1 = temp->z;
		draw->x2 = ft_iso_x((temp->next)->x, (temp->next)->y, glob);
		draw->y2 = ft_iso_y((temp->next)->x,
		(temp->next)->y, (temp->next)->z, glob);
		draw->z2 = (temp->next)->z;
		ft_draw_line(draw, glob, ft_color(draw));
		temp = temp->next;
		if (i == glob->x && temp->next)
		{
			temp = temp->next;
			i = 0;
		}
		i++;
	}
}

int		ft_max_y(t_data **data)
{
	t_data	*temp;
	int		y;

	y = 0;
	temp = *data;
	while (temp)
	{
		if (temp->y > y)
			y = temp->y;
		temp = temp->next;
	}
	return (y);
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
	t_draw	*draw;
	t_glob	glob;

	draw = (t_draw*)malloc(sizeof(t_draw));
	glob.mlx = mlx_init();
	glob.win = mlx_new_window(glob.mlx, WIDTH, HEIGHT, "fdf");
	glob.inc = 0;
	glob.zoom = 16;
	glob.move_x = 0;
	glob.move_y = 0;
	if (ac == 2)
	{
		if (!ft_fdf(draw, &glob, NULL, av[1]))
		{
			ft_putendl("Invalid map");
			return (0);
		}
	}
	mlx_hook(glob.win, 2, 1, ft_key, &glob);
	mlx_loop(glob.mlx);
}
