/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:51:47 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/09 17:42:21 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_list	*list;
	int		**tab;

	fd = open(av[1], O_RDONLY);
	list = ft_stock_lines(fd);
	tab = ft_stock_values(list);
	
	int i = -1;
	int j;
	while (++i <= 10)
	{
		j = -1;
		while(++j <= 17)
			printf("%d ", tab[i][j]);
		printf("\n");
	}
}

