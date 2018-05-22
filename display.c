/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:17:15 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 13:11:14 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_prepare_mlx(t_map *m)
{
	m->mlx = malloc(sizeof(t_minilibx));
	m->win_h = (((650 + m->h * 20) <= 1300) ? (650 + m->h * 20) : 1300);
	m->win_w = (((650 + m->w * 20) <= 2600) ? (650 + m->w * 20) : 2600);
	m->mlx->m_ptr = mlx_init();
	m->mlx->w = mlx_new_window(m->mlx->m_ptr, m->win_w, m->win_h, m->name);
	m->mlx->img.img_ptr = mlx_new_image(m->mlx->m_ptr, m->win_w, m->win_h);
	m->mlx->img.data = (int *)mlx_get_data_addr(m->mlx->img.img_ptr,
&m->mlx->img.bpp, &m->mlx->img.size_l, &m->mlx->img.endian);
	m->p = malloc(sizeof(t_pixels));
	m->p->gap = 0;
	m->zoom = 0;
	m->mv_x = 0;
	m->mv_y = 0;
	m->act_x = 0;
	m->act_y = 0;
	m->coef_alt = 1;
	m->lines = 0;
	m->tuto = 0;
	ft_create_pixel_map(m);
	mlx_key_hook(m->mlx->w, key_events, m);
	mlx_loop_hook(m->mlx->m_ptr, ft_loop_events, m);
	mlx_hook(m->mlx->w, 17, 0, ft_exit, m);
	mlx_loop(m->mlx->m_ptr);
}

void	ft_create_pixel_map(t_map *m)
{
	int		i;
	int		line;

	line = 0;
	i = -1;
	if (m->p->gap == 0)
	{
		if (m->win_h > m->win_w)
			m->p->gap = (m->win_h) / (m->h * 1.8);
		else
			m->p->gap = (m->win_w) / (m->w * 1.8);
	}
	m->p->coord = malloc(sizeof(t_coord) * m->nb_points);
	while (++i < m->nb_points)
	{
		m->p->coord[i].x = 2 * m->act_x + (m->win_w / 2) - round(m->p->gap *
(m->w - m->h) / sqrt(3)) + ((i % m->w) - line) * m->p->gap;
		m->p->coord[i].y = 2 * m->act_y + (m->win_h / 2) - round(m->p->gap *
((m->w + m->h) / 4)) + round(((0.5) * (line + (i % m->w))) * m->p->gap) -
((m->coef_alt * m->p->gap * m->z[line][i % m->w])) / 7;
		if (!((i + 1) % m->w))
			line++;
	}
}

void	ft_build_image(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->nb_points)
	{
		if (map->p->coord[i].x >= 0 && map->p->coord[i].x < map->win_w &&
map->p->coord[i].y >= 0 && map->p->coord[i].y <
map->win_h && map->z[i / map->w][i % map->w] <= 0)
			map->mlx->img.data[map->p->coord[i].x + map->p->coord[i].y *
map->win_w] = map->color_bottom;
		if (map->p->coord[i].x >= 0 && map->p->coord[i].x < map->win_w &&
map->p->coord[i].y >= 0 && map->p->coord[i].y <
map->win_h && map->z[i / map->w][i % map->w] > 0)
			map->mlx->img.data[map->p->coord[i].x +
map->p->coord[i].y * map->win_w] = map->color_peak;
	}
}

void	ft_display(t_map *map)
{
	ft_create_pixel_map(map);
	ft_build_image(map);
	ft_trace_lines(map);
	mlx_put_image_to_window(map->mlx->m_ptr, map->mlx->w,
map->mlx->img.img_ptr, 0, 0);
	if (map->tuto)
		ft_tutorial(map);
}

void	ft_draw_point(t_coord point, t_map *map, int color)
{
	if (point.x >= 0 && point.x < map->win_w && point.y >= 0 &&
	point.y < map->win_h)
		map->mlx->img.data[point.x + point.y * map->win_w] = color;
}
