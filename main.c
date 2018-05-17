/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:51:47 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/17 18:08:56 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_list	*list;
	t_map	*map;
	char	*str_cp;

	if (ac == 2)
	{
		str_cp = ft_strdup(av[1]);
		fd = open(av[1], O_RDONLY);
		list = ft_stock_lines(fd);
		map = ft_stock_values(list);
		ft_get_name(map, str_cp);
		ft_prepare_mlx(map);
	}
}