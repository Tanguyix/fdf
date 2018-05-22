/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:50:21 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 10:50:00 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_events(int key, t_map *map)
{
	if (key == 53)
	{
		ft_free_map(map);
		exit(0);
	}
	else if (key == 125 || key == 126 || key == 0 || key == 2 || key == 13 ||
	key == 1)
		ft_change_loop(key, map);
	else if (key == 69)
		map->coef_alt++;
	else if (key == 78)
		map->coef_alt--;
	else if (key == 15)
		ft_reset(map);
	else if (key == 49)
		ft_stop(map);
	else if (key == 37)
		map->lines++;
	else
		map->tuto = (!(map->tuto) ? 1 : 0);
	return (0);
}

void	ft_reset(t_map *map)
{
	map->zoom = 0;
	map->coef_alt = 1;
	if (map->win_height > map->win_width)
		map->pixels->gap = (map->win_height) / (map->height * 1.8);
	else
		map->pixels->gap = (map->win_width) / (map->width * 1.8);
	map->lines = 0;
	map->act_x = 0;
	map->act_y = 0;
	map->mv_x = 0;
	map->mv_y = 0;
}

int		ft_loop_events(t_map *map)
{
	int	i;

	i = -1;
	if ((map->pixels->gap < 150 && map->zoom > 0) ||
	(map->pixels->gap > 1 && map->zoom < 0))
		map->pixels->gap += map->zoom;
	if (map->pixels->gap == 0)
		return (0);
	ft_bzero(map->mlx->img.data, sizeof(int) * (map->win_h * map->win_w));
	map->act_y += map->mv_y;
	if (abs(map->act_y) > map->win_h / 3)
	{
		map->act_y = ((map->act_y > 0) ? (map->win_h / 3) : (-map->win_h / 3));
		map->mv_y = -map->mv_y;
	}
	map->act_x += map->mv_x;
	if (abs(map->act_x) > map->win_w / 3)
	{
		map->act_x = ((map->act_x > 0) ? (map->win_w / 3) : (-map->win_w / 3));
		map->mv_x = -map->mv_x;
	}
	free(map->pixels->coord);
	ft_display(map);
	return (0);
}

void	ft_change_loop(int key, t_map *map)
{
	if (key == 125)
	{
		map->zoom -= 0.1;
		if (map->zoom > 0)
			map->zoom = 0;
	}
	if (key == 126)
	{
		map->zoom += 0.1;
		if (map->zoom < 0)
			map->zoom = 0;
	}
	if (key == 0)
	{
		map->mv_x -= 1;
		if (map->mv_x > 0)
			map->mv_x = 0;
	}
	ft_change_loop_2(key, map);
}

void	ft_change_loop_2(int key, t_map *map)
{
	if (key == 2)
	{
		map->mv_x += 1;
		if (map->mv_x < 0)
			map->mv_x = 0;
	}
	if (key == 13)
	{
		map->mv_y -= 1;
		if (map->mv_y > 0)
			map->mv_y = 0;
	}
	if (key == 1)
	{
		map->mv_y += 1;
		if (map->mv_y < 0)
			map->mv_y = 0;
	}
}
