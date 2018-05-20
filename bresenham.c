/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:15:13 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/20 17:14:34 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_draw_point(t_coord point, t_map *map, int color)
{
    if (point.x >= 0 && point.x < map->win_width && point.y >= 0 && point.y < map->win_height)
            map->mlx->img.data[point.x + point.y * map->win_width] = color;    
}

void    ft_bresenham_low(t_coord p1, t_coord p2, t_map *map, int color)
{
    t_coord d;
    int     yi;
    t_coord point;
    int     D;

    d.x = p2.x - p1.x;
    d.y = p2.y - p1.y;
    yi = 1;
    if (d.y < 0)
    { 
        yi = -1;
        d.y = -1 * d.y;
    }
    D = 2 * d.y - d.x;
    point.y = p1.y;
    point.x = p1.x;
    while (point.x != p2.x)
    {
        ft_draw_point(point, map, color);
        if (D > 0)
        {
            point.y = point.y + yi;
            D = D - 2 * d.x;
        }
        D = D + 2 * d.y;
        point.x++;
    }
}

void    ft_bresenham_high(t_coord p1, t_coord p2, t_map *map, int color)
{
    t_coord d;
    int     xi;
    t_coord point;
    int     D;

    d.x = p2.x - p1.x;
    d.y = p2.y - p1.y;
    xi = 1;
    if (d.x < 0)
    { 
        xi = -1;
        d.x = -1 * d.x;
    }
    D = 2 * d.x - d.y;
    point.y = p1.y;
    point.x = p1.x;
    while (point.y != p2.y)
    {
        ft_draw_point(point, map, color);
        if (D > 0)
        {
            point.x = point.x + xi;
            D = D - 2 * d.y;
        }
        D = D + 2 * d.x;
        point.y++;
    }
}

void    ft_bresenham(t_coord p1, t_coord p2, t_map *map, int color)
{
    if (abs(p2.y - p1.y) < abs(p2.x - p1.x))
    {
        if (p1.x > p2.x)
            ft_bresenham_low(p2, p1, map, color);
        else
            ft_bresenham_low(p1, p2, map, color);
    }
    else
    {
        if (p1.y > p2.y)
            ft_bresenham_high(p2, p1, map, color);
        else
            ft_bresenham_high(p1, p2, map, color);
    }
}

void    ft_trace_lines(t_map *map)
{
    int     i;
    int color;
    
    i = -1;
    while (++i < map->nb_points)
    {
        if(!((map->lines + 1) % 4))
            return;
            if (!i || ((i + 1) % map->width))
        {
        if (!(map->z[i / map->width][i % map->width]) && !(map->z[(i + 1)/map->width][(i + 1)% map->width]))
            color = map->color_bottom;
        else if (map->z[i / map->width][i % map->width] || map->z[(i + 1)/map->width][(i + 1)% map->width])
            color = map->color_peak;
            if ((!(map->lines) || ((map->lines + 2) % 4)) && (((map->pixels->coord[i].x >= 0) && (map->pixels->coord[i].x <= map->win_width)) ||
            ((map->pixels->coord[i + 1].x >= 0) && (map->pixels->coord[i + 1].x <= map->win_width))) &&
            (((map->pixels->coord[i].y >= 0) && (map->pixels->coord[i].y <= map->win_height)) ||
            ((map->pixels->coord[i + 1].y >= 0) && (map->pixels->coord[i + 1].y <= map->win_height))))
                ft_bresenham(map->pixels->coord[i], map->pixels->coord[i + 1], map, color);
        }
    }
    i = -1;
    while (++i < map->nb_points - map->width)
    {
        if (!(map->z[i / map->width][i % map->width]) && !(map->z[(i + map->width)/map->width][(i + map->width)% map->width]))
            color = map->color_bottom;
        else if (map->z[i / map->width][i % map->width] || map->z[(i + map->width)/map->width][(i + map->width)% map->width])
            color = map->color_peak;
          if ((!(map->lines) || ((map->lines + 3) % 4)) && (((map->pixels->coord[i].x >= 0) && (map->pixels->coord[i].x <= map->win_width)) ||
            ((map->pixels->coord[i + map->width].x >= 0) && (map->pixels->coord[i + map->width].x <= map->win_width))) &&
            (((map->pixels->coord[i].y >= 0) && (map->pixels->coord[i].y <= map->win_height)) ||
            ((map->pixels->coord[i + map->width].y >= 0) && (map->pixels->coord[i + map->width].y <= map->win_height))))
        ft_bresenham(map->pixels->coord[i], map->pixels->coord[i + map->width], map, color);
    }
}