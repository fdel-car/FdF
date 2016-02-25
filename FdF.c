/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:46:07 by fdel-car          #+#    #+#             */
/*   Updated: 2016/02/25 19:04:07 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include "FdF.h"

/*void	ft_draw_line(int **data, void *mlx, void *win)
{
}*/

void	ft_set_data(char **tab, int y, int **data)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		data[y] = (int *)malloc(sizeof(int) * 3);
		data[y][0] = i;
		data[y][1] = y;
		data[y][2] = ft_atoi(tab[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_glob	glob;
	//int		**data;
	int		fd;
	char	*line;
	char	**tab;
	int		y;

	y = 0;
	if (ac == 2)
	{
		fd = open (av[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			tab = ft_strsplit(line, ' ');
			//ft_set_data(tab, y, data);
			y++;
		}
	}
	else
		return (0);
	glob.mlx = mlx_init();
	glob.win = mlx_new_window(glob.mlx, 600, 400, "FdF");
	//ft_draw_line(data, glob.mlx, glob.win);
	mlx_loop(glob.mlx);
}
