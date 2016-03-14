/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:46:07 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/14 18:07:39 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"

void	ft_addend(t_data **data, t_data *new)
{
	t_data *temp;

	temp = *data;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int		ft_set_data(char **tab, int y, t_data *data, int i)
{
	t_data		*new;
	static int	x;

	while (tab[i])
	{
		new = (t_data *)malloc(sizeof(t_data));
		new->x = i;
		new->y = y;
		new->z = ft_atoi(tab[i]);
		new->next = NULL;
		ft_addend(&data, new);
		i++;
	}
	if (x == 0)
		x = i;
	if (x != i)
	{
		ft_putendl("Invalid map, there must be the same numbers of coordinates on each line");
		return (1);
	}
	return (0);
}

t_data	*ft_createdata(char **tab, int y)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->x = 0;
	data->y = y;
	data->z = ft_atoi(tab[0]);
	data->next = NULL;
	return (data);
}

t_data	*ft_init(char *str)
{
	t_glob	glob;
	t_data	*data;
	char	*line;
	char	**tab;

	glob.y = 0;
	glob.fd = open(str, O_RDONLY);
	while ((get_next_line(glob.fd, &line)) == 1)
	{
		tab = ft_strsplit(line, ' ');
		if (glob.y == 0)
		{
			data = ft_createdata(tab, glob.y);
			if (ft_set_data(tab, glob.y, data, 1) == 1)
				return (NULL);
		}
		else
			if (ft_set_data(tab, glob.y, data, 0) == 1)
				return (NULL);
		free(tab);
		glob.y++;
	}
	return (data);
}
