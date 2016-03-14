/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:32:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/14 18:03:18 by fdel-car         ###   ########.fr       */
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
	void			*mlx;
	void			*win;
	int				fd;
	int				x;
	int				y_max;
	int				y;
	char			*str;
	t_data			*data;
	t_draw			*draw;
}					t_glob;

int					ft_key(int keycode, t_glob *glob);
int					ft_fdf(t_draw *draw, t_glob *glob, t_data *data, char *str);
void				ft_draw_ver(t_data **data, t_glob *glob, t_draw *draw, int i);
void				ft_draw_hor(t_data **data, t_glob *glob, t_draw *draw);
int					ft_max_x(t_data **data);
int					ft_max_y(t_data **data);
t_data				*ft_init(char *str);
void				ft_draw_line(t_draw *draw, t_glob *glob,
					unsigned int color);
int					ft_iso(int x, int y, int z, int which);

#endif
