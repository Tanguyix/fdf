/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:09:32 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 10:16:27 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tutorial(t_map *m)
{
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 10, m->h / 15, W, "ESC");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 250, m->h / 15, W, "quit");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 10, m->h / 15 + 25, W, "WASD");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 250, m->h / 15 + 25, W,
	"movements");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 10, m->h / 15 + 50, W,
	"Up and Down arrows");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 250, m->h / 15 + 50, W,
	"zoom in and out");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 10, m->h / 15 + 75, W, "L");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 250, m->h / 15 + 75, W,
	"toggle lines");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 10, m->h / 15 + 100, W, "R");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 250, m->h / 15 + 100, W,
	"reset all");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 10, m->h / 15 + 125, W, "space");
	mlx_string_put(m->mlx->m_ptr, m->mlx->w, 250, m->h / 15 + 125, W,
	"stop movements");
}
