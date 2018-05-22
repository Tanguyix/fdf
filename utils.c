/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:44:55 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 13:11:46 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_name(t_map *map, char *av)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	while (i && av[i] != '/')
		i--;
	if (av[i] == '/')
		i++;
	map->name = ft_strdup(&av[i]);
}

void	ft_usage(void)
{
	ft_putstr("Usage : ./fdf <-b R, G, B(color altitude 0) -p R ,G , B");
	ft_putstr("(color above 0)> <fichier.fdf>\n");
}

void	ft_line_too_short(int i)
{
	ft_putstr("Warning : Line ");
	ft_putnbr(i + 1);
	ft_putstr(" of your fdf file is too short.\n");
	ft_putstr("Forgotten values have been replaced with zeroes\n");
}

void	ft_free_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->h)
		free(map->z[i]);
	free(map->z);
	i = -1;
	free(map->mlx->img.data);
	free(map->mlx->img.img_ptr);
	free(map->mlx->m_ptr);
	free(map->mlx->w);
	free(map->mlx);
	free(map->p);
	ft_strdel(&map->name);
	free(map);
}

void	ft_error_window(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->mlx = malloc(sizeof(t_minilibx));
	map->mlx->m_ptr = mlx_init();
	map->mlx->w = mlx_new_window(map->mlx->m_ptr, 800, 600,
	"ERROR, and a great FdF bonus");
	mlx_string_put(map->mlx->m_ptr, map->mlx->w, 230, 280, 0xFFFFFF,
	"Error fdf file, press any key to exit");
	mlx_key_hook(map->mlx->w, ft_exit, map);
	mlx_hook(map->mlx->w, 17, 0, ft_exit, map);
	mlx_loop(map->mlx->m_ptr);
}
