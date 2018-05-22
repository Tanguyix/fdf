/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:15:13 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 12:17:19 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham_low(t_coord p1, t_coord p2, t_map *map, int color)
{
	t_coord	d;
	t_coord	point;
	t_coord r;

	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	r.y = 1;
	if (d.y < 0)
	{
		r.y = -1;
		d.y = -1 * d.y;
	}
	r.x = 2 * d.y - d.x;
	point.y = p1.y;
	point.x = p1.x;
	while (point.x != p2.x)
	{
		ft_draw_point(point, map, color);
		if (((point.x++) || (1)) && r.x > 0)
		{
			point.y = point.y + r.y;
			r.x = r.x - 2 * d.x;
		}
		r.x = r.x + 2 * d.y;
	}
}

void	ft_bresenham_high(t_coord p1, t_coord p2, t_map *map, int color)
{
	t_coord	d;
	t_coord	point;
	t_coord r;

	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	r.x = 1;
	if (d.x < 0)
	{
		r.x = -1;
		d.x = -1 * d.x;
	}
	r.y = 2 * d.x - d.y;
	point.y = p1.y;
	point.x = p1.x;
	while (point.y != p2.y)
	{
		ft_draw_point(point, map, color);
		if (((point.y++) || (1)) && r.y > 0)
		{
			point.x = point.x + r.x;
			r.y = r.y - 2 * d.y;
		}
		r.y = r.y + 2 * d.x;
	}
}

void	ft_bresenham(t_coord p1, t_coord p2, t_map *map, int color)
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

void	ft_trace_lines(t_map *m)
{
	int	i;
	int	color;

	i = -1;
	while (++i < m->nb_points)
	{
		if (!((m->lines + 1) % 4))
			return ;
		if (!i || ((i + 1) % m->w))
		{
			if (!(m->z[i / m->w][i % m->w]) &&
!(m->z[(i + 1) / m->w][(i + 1) % m->w]))
				color = m->color_bottom;
			else if (m->z[i / m->w][i % m->w] ||
m->z[(i + 1) / m->w][(i + 1) % m->w])
				color = m->color_peak;
			if ((!(m->lines) || ((m->lines + 2) % 4)) &&
(((m->p->coord[i].x >= 0) && (m->p->coord[i].x <= m->win_w)) ||
((m->p->coord[i + 1].x >= 0) && (m->p->coord[i + 1].x <= m->win_w))) &&
(((m->p->coord[i].y >= 0) && (m->p->coord[i].y <= m->win_h)) ||
((m->p->coord[i + 1].y >= 0) && (m->p->coord[i + 1].y <= m->win_h))))
				ft_bresenham(m->p->coord[i], m->p->coord[i + 1], m, color);
		}
	}
	ft_trace_lines2(m);
}

void	ft_trace_lines2(t_map *m)
{
	int	i;
	int color;

	i = -1;
	while (++i < m->nb_points - m->w)
	{
		if (!(m->z[i / m->w][i % m->w]) &&
!(m->z[(i + m->w) / m->w][(i + m->w) % m->w]))
			color = m->color_bottom;
		else if (m->z[i / m->w][i % m->w] ||
m->z[(i + m->w) / m->w][(i + m->w) % m->w])
			color = m->color_peak;
		if ((!(m->lines) || ((m->lines + 3) % 4)) &&
(((m->p->coord[i].x >= 0) && (m->p->coord[i].x <= m->win_w)) ||
((m->p->coord[i + m->w].x >= 0) && (m->p->coord[i + m->w].x <= m->win_w))) &&
(((m->p->coord[i].y >= 0) && (m->p->coord[i].y <= m->win_h)) ||
((m->p->coord[i + m->w].y >= 0) && (m->p->coord[i + m->w].y <= m->win_h))))
			ft_bresenham(m->p->coord[i], m->p->coord[i + m->w], m, color);
	}
}
