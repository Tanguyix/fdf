/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:03:49 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/09 17:58:03 by tboissel         ###   ########.fr       */
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
		}
		if (cpt > max)
			max = cpt;
		list = list->next;
	}
	return (max);
}

int				**ft_stock_values(t_list *list)
{
	int			**values;
	int			i;
	int			k;
	int			j;

	i = ft_lst_size(list);
	if (!(values = (int **)malloc(sizeof(int *) * ft_lst_size(list))))
		return (NULL);
	while (list)
	{
		j = -1;
		k = -1;
		if (!(values[--i] = (int *)malloc(sizeof(int) * ft_max_size(list))))
			return (NULL);
		while (((char *)list->content)[++j] && k <= ft_max_size(list))
			if (ft_isdigit(((char *)list->content)[j]))
			{
				values[i][++k] = ft_atoi(&((char *)list->content)[j]);
				while (((char*)list->content)[j + 1] != ' ')
					j++;
			}
		list = list->next;
	}
	return (values);
}
