/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:32:11 by fdel-car          #+#    #+#             */
/*   Updated: 2018/09/19 15:35:55 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct		s_data
{
	int				x;
	int				y;
	int				z;
	struct s_data	*next;
}					t_data;

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
	int				xinc;
	int				yinc;
	int				cumul;
	int				i;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_draw;

typedef struct		s_glob
{
	int				i;
	void			*mlx;
	void			*win;
	int				fd;
	int				x;
	int				y_max;
	int				y;
	int				help;
	int				width;
	int				height;
	char			*disp;
	t_data			*data;
	t_draw			*draw;
	char			*str;
	int				inc;
	int				stat;
	int				zoom;
	int				move_x;
	int				move_y;
	int				color;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_glob;

int					ft_key(int keycode, t_glob *glob);
int					ft_fdf(t_draw *draw, t_glob *glob, t_data *data, char *str);
void				ft_draw_ver(t_data **data, t_glob *glob,
					t_draw *draw, int i);
void				ft_draw_hor(t_data **data, t_glob *glob, t_draw *draw);
int					ft_max_x(t_data **data);
int					ft_max_y(t_data **data);
t_data				*ft_init(t_glob *glob);
void				ft_draw_line(t_draw *draw, t_glob *glob,
					unsigned int color);
int					ft_iso_x(int x, int y, t_glob *glob);
int					ft_iso_y(int x, int y, int z, t_glob *glob);
int					ft_color(t_draw *draw, t_glob *glob);
void				ft_putstring(t_glob *glob);

#endif
