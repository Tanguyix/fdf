/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:44:55 by tboissel          #+#    #+#             */
/*   Updated: 2018/06/19 15:57:01 by tboissel         ###   ########.fr       */
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
	ft_putstr("Usage : ./fdf -b R G B -zero altitude color- -p R G B");
	ft_putstr(" -above 0 altitude color-");
	ft_putstr("(color above 0)) <fichier.fdf>\n");
	ft_putstr("Undefined behaviour if less than 3 values are defined\n");
}

void	ft_line_too_short(int i)
{
	ft_putstr("Warning : Line ");
	ft_putnbr(i + 1);
	ft_putstr(" of your fdf file is too short.\n");
	ft_putstr("Forgotten values have been replaced with zeroes\n");
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
