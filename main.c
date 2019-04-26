/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:51:47 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/25 11:42:12 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_list	*list;
	t_map	*map;
	int		i;

	i = 0;
	if (ac == 1)
		ft_usage();
	else
	{
		fd = open(av[ac - 1], O_RDONLY);
		list = ft_stock_lines(fd);
		if (!(map = malloc(sizeof(t_map))))
			return (0);
		ft_stock_values(list, map);
		ft_lstdel(&list, &ft_del);
		map->color_peak = W;
		map->color_bottom = W;
		while (++i < ac - 1)
			if (av[i][0] == '-')
				ft_get_color(av[i][1], av[i + 1], map);
		ft_get_name(map, av[ac - 1]);
		ft_prepare_mlx(map);
	}
	return (0);
}
