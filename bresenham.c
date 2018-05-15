/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:15:13 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/15 15:31:27 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_bresenham(t_coord p1, t_coord p2, t_minilibx mlx)
{}

void    ft_trace_lines(t_minilibx mlx, t_pixels pixels, t_map *map)
{
    int     i;
    
    i = -1;
    while (++i < map->nb_points)
        ft_bresenham(pixels.coord[i], pixels.coord[i + 1], mlx);
    i = -1;
    while (++i < map->nb_points - map->width)
        ft_bresenham(pixels.coord[i], pixels.coord[i + map->width], mlx);

}