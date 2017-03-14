/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:46:07 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/16 22:07:42 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "fdf.h"
#include <unistd.h>

void	ft_addend(t_data **data, t_data *new)
{
	t_data *temp;

	temp = *data;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int		ft_set_data(char **tab, t_glob *glob, t_data *data, int i)
{
	t_data		*new;
	static int	x;

	while (tab[i])
	{
		new = (t_data *)malloc(sizeof(t_data));
		new->x = i;
		new->y = glob->y;
		new->z = ft_atoi(tab[i]);
		if (new->z != 0)
			new->z = new->z * glob->inc;
		new->next = NULL;
		ft_addend(&data, new);
		i++;
	}
	if (x == 0)
		x = i;
	if (x != i)
		return (1);
	return (0);
}

t_data	*ft_createdata(char **tab, t_glob *glob)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->x = 0;
	data->y = glob->y;
	data->z = ft_atoi(tab[0]);
	if (data->z != 0)
		data->z = data->z * glob->inc;
	data->next = NULL;
	return (data);
}

t_data	*ft_init(t_glob *glob)
{
	t_data	*data;
	char	*line;
	char	**tab;
	int		iter;

	iter = 0;
	while ((glob->i = (get_next_line(glob->fd, &line))) == 1)
	{
		tab = ft_strsplit(line, ' ');
		if (glob->y == 0)
		{
			data = ft_createdata(tab, glob);
			if (ft_set_data(tab, glob, data, 1) == 1)
				return (NULL);
		}
		else
		{
			if (ft_set_data(tab, glob, data, 0) == 1)
				return (NULL);
		}
		while (tab[iter])
			free(tab[iter++]);
		free(tab);
		free(line);
		glob->y++;
	}
	free(line);
	if (glob->i <= 0 && !glob->y)
		return (NULL);
	return (data);
}
