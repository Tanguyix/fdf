/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:38:41 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 13:12:42 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit(int key, t_map *map)
{
	key = map->coef_alt;
	exit(0);
	return (0);
}

void	ft_stop(t_map *map)
{
	map->zoom = 0;
	map->mv_x = 0;
	map->mv_y = 0;
}
