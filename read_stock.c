/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:24:03 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/09 13:54:20 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list		*ft_stock_lines(int fd)
{
	t_list		*list_lines;
	char		*tmp;

	list_lines = NULL;
	while (get_next_line(fd, &tmp))
	{
		if (list_lines == NULL)
			ft_lstnew(tmp, ft_strlen(tmp));
		else
			ft_lstadd(*list_lines, ft_lstnew(tmp, ft_strlen(tmp)));
		free(tmp);
	}
}

int			ft_max_size(t_list *list)
{
	int		max;
	int		cpt;

	max = 0;
	while (list)
	{
		cpt = 1;
		while (list->content)
		{
			if (list->content == ' ')
				cpt++;
			list->content++;
		}
		if (cpt > max)
			max = cpt;
		list = list->next;
	}
	return (max);
}

int		**ft_stock_values(t_list *list)
{
	int		**fdf_values;
	int		i;

	i = 0;
	if (!(fdf_values = (int **)malloc(sizeof(int*) * ft_lst_size(list))))
		return (NULL);
	while (list)
	{
		if (!(*fdf_values = (int *)malloc(sizeof(int) * ft_max_size(list))))
			return (NULL);
		while (list->content)
		{
			if (ft_isdigit(*list->content) || *list->content == '-')
				fdf_values[i] = ft_atoi(list->content);
			list->content++;
		}
		i++;
	}
	return (fdf_values);
}
