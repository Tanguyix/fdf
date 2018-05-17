/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:17:15 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/17 19:24:01 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_prepare_mlx(t_map *map)
{
	map->mlx = malloc(sizeof(t_minilibx));
	map->win_height = ((550 + map->height * 20) <= 1300) ? (550 + map->height * 20): 1300; 
	map->win_width = ((550 + map->width * 20) <= 2600) ? (550 + map->width * 20) : 2600;
	map->mlx->mlx_ptr = mlx_init();
	map->mlx->win = mlx_new_window(map->mlx->mlx_ptr, map->win_width, map->win_height, map->name);
	map->mlx->img.img_ptr = mlx_new_image(map->mlx->mlx_ptr, map->win_width, map->win_height);
	map->mlx->img.data = (int *)mlx_get_data_addr(map->mlx->img.img_ptr, &map->mlx->img.bpp, &map->mlx->img.size_l, &map->mlx->img.endian);
	map->pixels = malloc(sizeof(t_pixels));
	map->pixels->gap = 0;
	map->zoom = 0;
	map->mv_x = 0;
	map->mv_y = 0;
	map->act_x = 0;
	map->act_y = 0;
	map->coef_alt = 1;
	ft_create_pixel_map(map);
	mlx_key_hook(map->mlx->win, key_events, map);
	mlx_loop_hook(map->mlx->mlx_ptr, ft_loop_events, map);
	mlx_hook(map->mlx->win, 17, 0, ft_exit, 0);
	mlx_loop(map->mlx->mlx_ptr);
}

void	ft_create_pixel_map(t_map *map)
{
	int			i;
	int			line;
	float		coef_alt;

	line = 0;
	i = -1;
	if (map->pixels->gap == 0)
	{
		if (map->win_height > map->win_width)
			map->pixels->gap = (map->win_height) / (map->height * 1.8);
		else
			map->pixels->gap = (map->win_width) / (map->width * 1.8);
	}
	map->pixels->coord = malloc(sizeof(t_coord) * map->nb_points);
	while (++i < map->nb_points)
	{
		map->pixels->coord[i].x = 5 * map->act_x + (map->win_width / 2) - round(map->pixels->gap * (map->width - map->height) / sqrt(3)) + ((i % map->width) - line) * map->pixels->gap;
		map->pixels->coord[i].y = 5 * map->act_y + (map->win_height / 2) - round(map->pixels->gap * ((map->width + map->height) / 4)) + round(((0.5) * (line + (i % map->width))) * map->pixels->gap) - ((map->coef_alt * map->pixels->gap * map->z[line][i % map->width])) / 6;
		if (!((i + 1) % map->width))
			line++;
	}
	
}

void	ft_build_image(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->nb_points)
	{
		if (map->pixels->coord[i].x >= 0 && map->pixels->coord[i].x < map->win_width && map->pixels->coord[i].y >= 0 && map->pixels->coord[i].y < map->win_height)
			map->mlx->img.data[map->pixels->coord[i].x + map->pixels->coord[i].y * map->win_width] = 0xFFFFFF;
	}
}