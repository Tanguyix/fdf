/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:17:15 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/14 18:39:48 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_prepare_mlx(t_map *map)
{
	t_minilibx	mlx;
	t_pixels	pixels;
	
	map->win_height = map->height * 75;
	map->win_width = map->width * 75;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, map->win_width, map->win_height, "test");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, map->win_width, map->win_height);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	
	pixels = ft_create_pixel_map(map);
	ft_build_image(mlx, map, pixels);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}

t_pixels	ft_create_pixel_map(t_map *map)
{
	t_pixels	pixels;
	int			i;
	int			line;

	line = 0;
	i = -1;
	pixels.gap = (map->win_height) / (map->height * 1.4);
	pixels.coord = malloc(sizeof(t_coord) * map->nb_points);
	printf("avant seg\n");
	while (++i < map->nb_points)
	{
		pixels.coord[i].x = round((double)(350 + (((i % map->width) * 1 / sqrt(3) - (line * (1 / 2))) * pixels.gap)));
		pixels.coord[i].y = round(250 + (((i % map->width) - line ) * pixels.gap) / 2);
		if (!((i + 1) % map->width))
			line++;
		printf("point %d x = %d y = %d\n", i, pixels.coord[i].x, pixels.coord[i].y);
	}
	return (pixels);
}

void	ft_build_image(t_minilibx mlx, t_map *map, t_pixels pixels)
{
	int		height;
	int		width;
	int		i;

	i = 0;
	height = -1;
	while (++height <= map->win_height)
	{
		width = -1;
		while (++width <= map->win_width)
			{
				if (height == pixels.coord[i].y && width == pixels.coord[i].x)
				{
					mlx.img.data[height * map->win_width + width] = 0xFFFFFF;
					i++;
					height = -1;
				}
			}
	}
}