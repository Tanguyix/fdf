/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:17:15 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/17 10:45:44 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_prepare_mlx(t_map *map)
{
	map->win_height = ((400 + map->height * 20) <= 1300) ? (400 + map->height * 20): 1300; 
	map->win_width = ((400 + map->width * 20) <= 2600) ? (400 + map->width * 20) : 2600;
	map->mlx.mlx_ptr = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.mlx_ptr, map->win_width, map->win_height, "test");
	map->mlx.img.img_ptr = mlx_new_image(map->mlx.mlx_ptr, map->win_width, map->win_height);
	map->mlx.img.data = (int *)mlx_get_data_addr(map->mlx.img.img_ptr, &map->mlx.img.bpp, &map->mlx.img.size_l, &map->mlx.img.endian);
	
	map->pixels = ft_create_pixel_map(map);
	ft_build_image(map);
	ft_trace_lines(map);
	mlx_put_image_to_window(map->mlx.mlx_ptr, map->mlx.win, map->mlx.img.img_ptr, 0, 0);
	mlx_key_hook(map->mlx.win, key_events, 0);
	mlx_hook(map->mlx.win, 17, 0, &ft_exit, 0);
	mlx_loop(map->mlx.mlx_ptr);
}

t_pixels	ft_create_pixel_map(t_map *map)
{
	t_pixels	pixels;
	int			i;
	int			line;
	float		coef_alt;

	line = 0;
	i = -1;
	if (map->win_height > map->win_width)
		pixels.gap = (map->win_height) / (map->height * 1.8);
	else
		pixels.gap = (map->win_width) / (map->width * 1.8);
	coef_alt = pixels.gap / 4;
	pixels.coord = malloc(sizeof(t_coord) * map->nb_points);
	while (++i < map->nb_points)
	{
		pixels.coord[i].x = (map->win_width / 2) - round(pixels.gap * (map->width - map->height) / sqrt(3)) + ((i % map->width) - line) * pixels.gap;
		pixels.coord[i].y = (map->win_height / 2) - round(pixels.gap * ((map->width + map->height) / 4)) + round(((0.5) * (line + (i % map->width))) * pixels.gap) - coef_alt * map->z[line][i % map->width];
		if (!((i + 1) % map->width))
			line++;
	}
	return (pixels);
}

void	ft_build_image(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->nb_points)
	{
		if (map->pixels.coord[i].x >= 0 && map->pixels.coord[i].x < map->win_width && map->pixels.coord[i].y >= 0 && map->pixels.coord[i].y < map->win_height)
			map->mlx.img.data[map->pixels.coord[i].x + map->pixels.coord[i].y * map->win_width] = 0xFFFFFF;
	}
}