/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:03:49 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/16 16:02:37 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list			*ft_stock_lines(int fd)
{
	t_list		*list_lines;
	char		*tmp;

	list_lines = NULL;
	while (get_next_line(fd, &tmp))
	{
		if (list_lines == NULL)
			list_lines = ft_lstnew(tmp, ft_strlen(tmp) + 1);
		else
			ft_lstadd(&list_lines, ft_lstnew(tmp, ft_strlen(tmp) + 1));
		free(tmp);
	}
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
		cpt = 1;
		while (((char *)list->content)[++i])
		{
			if (ft_isspace(((char *)list->content)[i]))
				cpt++;
			while (ft_isspace(((char *)list->content)[i]))
				i++;
		}
		if (cpt > max)
			max = cpt;
		list = list->next;
	}
	return (max);
}

t_map				*ft_stock_values(t_list *list)
{
	t_map		*map;
	int			i;
	int			k;
	int			j;


	i = ft_lst_size(list);
	if (!(map = (t_map *)malloc(sizeof(*map))))
		return (NULL);
	map->height = i;
	if (!(map->z = (int **)malloc(sizeof(int *) * ft_lst_size(list))))
		return (NULL);
	while (list)
	{
		j = -1;
		k = -1;
		map->width = ft_max_size(list);
		if (!(map->z[--i] = (int *)malloc(sizeof(int) * map->width)))
			return (NULL);
		while (((char *)list->content)[++j] && k <= map->width)
			if (ft_isdigit(((char *)list->content)[j]))
			{
				map->z[i][++k] = ft_atoi(&((char *)list->content)[j]);
				while (((char*)list->content)[j + 1] != ' ')
					j++;
			}
		list = list->next;
	}
	map->nb_points = map->height * map->width;
	return (map);
}
