/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:07:02 by tboissel          #+#    #+#             */
/*   Updated: 2018/06/19 15:15:28 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_color(char flag, char *av, t_map *map)
{
	if (av[0] == '-')
		return ;
	if (flag == 'b')
		map->color_bottom = ft_get_rgb(av);
	else if (flag == 'p')
		map->color_peak = ft_get_rgb(av);
	else
	{
		ft_usage();
		exit(0);
	}
}

int		ft_get_rgb(char *av)
{
	int		i;
	int		nb;
	int		rgb;
	int		add;

	rgb = 0;
	i = 0;
	nb = 65536;
	while (av[i])
	{
		while (av[i] == ',' || av[i] == ' ')
			i++;
		add = ((ft_atoi(&av[i]) < 255) ? ft_atoi(&av[i]) : 255);
		rgb += nb * add;
		nb /= 256;
		while (av[i] && ft_isdigit(av[i]))
			i++;
		while (!(ft_isdigit(av[i])))
			i++;
		if (nb == 0 || i > 13)
			break ;
	}
	return (rgb);
}
