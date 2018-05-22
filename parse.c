/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:03:49 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 10:36:57 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list			*ft_stock_lines(int fd)
{
	t_list		*list_lines;
	char		*tmp;
	int			ret;

	list_lines = NULL;
	while ((ret = get_next_line(fd, &tmp)) > 0)
	{
		if (list_lines == NULL)
			list_lines = ft_lstnew(tmp, ft_strlen(tmp) + 1);
		else
			ft_lstadd(&list_lines, ft_lstnew(tmp, ft_strlen(tmp) + 1));
		free(tmp);
	}
	if (tmp)
		free(tmp);
	if (ret == -1)
		ft_error_window();
	return (list_lines);
}

int				ft_max_size(t_list *list)
{
	int			max;
	int			cpt;
	int			i;

	max = 0;
	while (list)
	{
		i = -1;
		cpt = 0;
		while (((char *)list->content)[++i])
		{
			if (ft_isdigit(((char *)list->content)[i]))
				cpt++;
			while (((char *)list->content)[i + 1] &&
			ft_isdigit(((char *)list->content)[i]))
				i++;
		}
		if (cpt > max)
			max = cpt;
		list = list->next;
	}
	return (max);
}

int				ft_prepare_stock(t_list *list, t_map *map)
{
	int			i;

	i = ft_lst_size(list);
	map->h = i;
	if (!(map->z = malloc(sizeof(int *) * ft_lst_size(list))))
		return (0);
	map->width = ft_max_size(list);
	map->nb_points = map->height * map->width;
	return (i);
}

void			ft_stock_values(t_list *list, t_map *map)
{
	int			i;
	int			k;
	int			j;

	i = ft_prepare_stock(list, map);
	while (list)
	{
		j = -1;
		k = -1;
		if (!(map->z[--i] = (int *)malloc(sizeof(int) * map->width)))
			return ;
		while (((char *)list->content)[++j] && k <= map->width)
			if (ft_isdigit(((char *)list->content)[j]))
			{
				map->z[i][++k] = ft_atoi(&((char *)list->content)[j]);
				while (((char*)list->content)[j + 1] &&
				((char*)list->content)[j + 1] != ' ')
					j++;
			}
		if (k < map->width - 1)
			ft_line_too_short(i);
		while (k < map->width - 1)
			map->z[i][++k] = 0;
		list = list->next;
	}
}
