/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:32:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/05 00:01:21 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 1000

typedef struct		s_data
{
	int				x;
	int				y;
	int				z;
	struct s_data	*next;
}					t_data;

typedef struct		s_glob
{
	void			*mlx;
	void			*win;
	int				fd;
	int				x;
	int				y;
}					t_glob;

typedef struct		s_draw
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_draw;

t_data				*ft_init(char *str);
void				ft_draw_line(t_draw *draw, t_glob *glob,
					unsigned int color);
int					ft_iso(int x, int y, int which);

#endif
