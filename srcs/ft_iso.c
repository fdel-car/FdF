/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 23:42:15 by fdel-car          #+#    #+#             */
/*   Updated: 2018/09/19 15:34:26 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstring(t_glob *gl)
{
	if (gl->help == 0)
		return ;
	mlx_string_put(gl->mlx, gl->win, 60, gl->height + 20, ft_color(NULL, gl),
			"Zoom avant / Zoom arriere");
	mlx_string_put(gl->mlx, gl->win, 60, gl->height + 40, 0xFFFFFF,
			"Fleche du haut / Fleche du bas");
	mlx_string_put(gl->mlx, gl->win, 60, gl->height + 80, ft_color(NULL, gl),
			"Augmenter altitude / Baisser altitude");
	mlx_string_put(gl->mlx, gl->win, 60, gl->height + 100, 0xFFFFFF,
			"+ (numpad) / - (numpad)");
	mlx_string_put(gl->mlx, gl->win, 470, gl->height + 20, ft_color(NULL, gl),
			"Deplacer l'image");
	mlx_string_put(gl->mlx, gl->win, 470, gl->height + 40, 0xFFFFFF,
			"Haut : W, Bas : S, Gauche : A, Droite : D");
	mlx_string_put(gl->mlx, gl->win, 470, gl->height + 80, ft_color(NULL, gl),
			"Changer la couleur");
	mlx_string_put(gl->mlx, gl->win, 470, gl->height + 100, 0xFFFFFF,
			"Couleur precedente : fleche de gauche");
	mlx_string_put(gl->mlx, gl->win, 470, gl->height + 120, 0xFFFFFF,
			"Couleur suivante : fleche de droite");
	mlx_string_put(gl->mlx, gl->win, 950, gl->height + 20, ft_color(NULL, gl),
			"All reset");
	mlx_string_put(gl->mlx, gl->win, 950, gl->height + 40, 0xFFFFFF,
			"clear (numpad)");
}

int		ft_iso_y(int x, int y, int z, t_glob *glob)
{
	int i;

	i = (x + y) * glob->zoom + glob->height / 4 - z + glob->move_y;
	return (i);
}

int		ft_iso_x(int x, int y, t_glob *glob)
{
	int i;

	i = (x - y) * glob->zoom * 2 + glob->width / 2 + glob->move_x;
	return (i);
}
