/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:17:15 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/16 11:12:12 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_prepare_mlx(t_map *map)
{
	t_minilibx	mlx;
	t_pixels	pixels;
	
	map->win_height = ((400 + map->height * 20) <= 1300) ? (400 + map->height * 20): 1300; 
	map->win_width = ((400 + map->width * 20) <= 2600) ? (400 + map->width * 20) : 2600;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, map->win_width, map->win_height, "test");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, map->win_width, map->win_height);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	
	pixels = ft_create_pixel_map(map);
	ft_build_image(mlx, map, pixels);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win, key_events, 0);
	mlx_hook(mlx.win, 17, 0, &ft_exit, 0);
	mlx_loop(mlx.mlx_ptr);
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
	coef_alt = pixels.gap / 20;
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

void	ft_build_image(t_minilibx mlx, t_map *map, t_pixels pixels)
{
	int		i;

	i = -1;
	while (++i < map->nb_points)
	{
		if (pixels.coord[i].x >= 0 && pixels.coord[i].x < map->win_width && pixels.coord[i].y >= 0 && pixels.coord[i].y < map->win_height)
			mlx.img.data[pixels.coord[i].x + pixels.coord[i].y * map->win_width] = 0xFFFFFF;
	}
}