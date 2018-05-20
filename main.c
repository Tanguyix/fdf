/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:51:47 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/20 19:05:57 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_list	*list;
	t_map	*map;
	char	*str_cp;
	int		i;
	t_list	*lst_copy;
	
	i = 1;
	if (ac == 1)
	{
		ft_usage();
	}
	if (ac != 1)
	{
		str_cp = ft_strdup(av[(ac - 1)]);
		fd = open(av[ac - 1], O_RDONLY);
		list = ft_stock_lines(fd);
		map = ft_stock_values(list);
		map->color_peak = 0xFFFFFF;
		map->color_bottom = 0xFFFFFF;
		while (i < ac - 1)
		{
			if (av[i][0] == '-')
				ft_get_color(av[i][1], av[i + 1], map);
			i++;
		}
		ft_get_name(map, str_cp);
		ft_strdel(&str_cp);
		ft_prepare_mlx(map);
	}
	return (0);
}