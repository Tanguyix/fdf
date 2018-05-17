/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:04:03 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/17 18:46:54 by tboissel         ###   ########.fr       */
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
# include <unistd.h>

typedef struct			s_image
{
	void				*img_ptr;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
}						t_image;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_minilibx
{
	void				*mlx_ptr;
	void				*win;
	t_image				img;
}						t_minilibx;

typedef struct			s_pixels
{
	float				gap;
	struct s_coord		*coord;
}						t_pixels;

typedef struct			s_map
{
	int					width;
	int					height;
	int					nb_points;
	int					**z;
	int					win_height;
	int					win_width;
	float				zoom;
	t_minilibx			*mlx;
	t_pixels			*pixels;
	int					mv_x;
	int					mv_y;
	int					act_x;
	int					act_y;
	int					coef_alt;
	char				*name;
	int					color_bottom;
	int					color_peak;
}						t_map;

void					ft_prepare_mlx(t_map *map);
t_list					*ft_stock_lines(int fd);
int						ft_max_size(t_list *list);
t_map					*ft_stock_values(t_list *list);
void					ft_build_image(t_map *map);
void					ft_create_pixel_map(t_map *map);
void					ft_trace_lines(t_map *map);
void					ft_bresenham_high(t_coord p1, t_coord p2, t_map *map);
int						key_events(int key, t_map *map);
void					ft_bresenham_low(t_coord p1, t_coord p2, t_map *map);
void					ft_bresenham(t_coord p1, t_coord p2, t_map *map);
int						ft_exit(int key, void *param);
void					ft_draw_point(t_coord point, t_map *map);
void					ft_change_loop(int key, t_map *map);
int						ft_loop_events(t_map *map);
void					ft_mv_points(t_map *map);
void					ft_reset(t_map *map);
void					ft_stop(t_map *map);
void					ft_get_name(t_map *map, char *av1);
void					ft_usage(void);

#endif