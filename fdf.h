/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:04:03 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/15 16:11:03 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct			s_image
{
	void				*img_ptr;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
}						t_image;

typedef struct			s_minilibx
{
	void				*mlx_ptr;
	void				*win;
	struct s_image		img;
}						t_minilibx;

typedef struct			s_map
{
	int					width;
	int					height;
	int					nb_points;
	int					**z;
	int					win_height;
	int					win_width;
}						t_map;

typedef struct			s_pixels
{
	int					gap;
	struct s_coord		*coord;
}						t_pixels;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

void					ft_prepare_mlx(t_map *map);
t_list					*ft_stock_lines(int fd);
int						ft_max_size(t_list *list);
t_map					*ft_stock_values(t_list *list);
void					ft_build_image(t_minilibx mlx, t_map *map, t_pixels pixels);
t_pixels				ft_create_pixel_map(t_map *map);
void					ft_trace_lines(t_minilibx mlx, t_pixels pixels, t_map *map);
void					ft_bresenham(t_coord p1, t_coord p2, t_minilibx mlx);

#endif