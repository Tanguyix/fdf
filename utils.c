/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:44:55 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/21 12:10:33 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_get_name(t_map *map, char* av)
{
    int     i;
    
    i = 0;
    while (av[i])
        i++;
    while (i && av[i] != '/')
        i--;
    if (av[i] == '/')
        i++;
    map->name = ft_strdup(&av[i]);
}

void    ft_usage()
{
    ft_putstr("Usage : ./fdf <fichier.fdf>\n");
}

void    ft_line_too_short(int i)
{
    ft_putstr("Warning : Line ");
    ft_putnbr(i + 1);
    ft_putstr(" of your fdf file is too short.\nForgotten
 values have been replaced with zeroes\n");
}

void    ft_free_map(t_map *map)
{
    int     i;

    i = -1;
    while(++i < map->height)
        free(map->z[i]);
    free(map->z);
    i = -1;
    free(map->mlx->img.data);
    free(map->mlx->img.img_ptr);
    free(map->mlx->mlx_ptr);
    free(map->mlx->win);
    free(map->mlx);
    free(map->pixels);
    ft_strdel(&map->name);
    free(map);
}

void    ft_error_window(void)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    map->mlx = malloc(sizeof(t_minilibx));
    map->mlx->mlx_ptr = mlx_init();
	map->mlx->win = mlx_new_window(map->mlx->mlx_ptr, 800, 600, "ERROR, and a great FdF bonus");
    mlx_string_put(map->mlx->mlx_ptr, map->mlx->win, 230 , 280, 0xFFFFFF, "Error fdf file, press any key to exit");
    mlx_key_hook(map->mlx->win, ft_exit, map);
    mlx_hook(map->mlx->win, 17, 0, ft_exit, map);
    mlx_loop(map->mlx->mlx_ptr);
}