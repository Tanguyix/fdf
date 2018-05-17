/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:50:21 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/17 12:33:44 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int    key_events(int key, void *param)
{
    printf("%d\n", key);
    if (key == 53)
        exit(0);
    if (key == 125 || key == 126)
        ft_zoom(key, param);
    return (0);
}

int     ft_exit(int key, void *param)
{
    exit(0);
    return (0);
}

int     ft_loop_events(t_map *map)
{
    printf("%f\n", map->zoom);
    map->pixels->gap += map->zoom;
    map->pixels->gap = fabs(map->pixels->gap);
    if (map->pixels->gap == 0)
        return (0);
    ft_bzero(map->mlx->img.data, sizeof(int) * (map->win_height * map->win_width));
	ft_create_pixel_map(map);
	ft_build_image(map);
	ft_trace_lines(map);
	mlx_put_image_to_window(map->mlx->mlx_ptr, map->mlx->win, map->mlx->img.img_ptr, 0, 0);
    return (0);
}

void    ft_zoom(int key, t_map *map)
{
    if (key == 125)
        map->zoom -= 0.1;
    if (key == 126)
        map->zoom += 0.1;
}