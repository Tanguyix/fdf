/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:04:03 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/09 17:59:15 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct			s_fdflist
{
	char				*line;
	int					size;
	struct s_fdflist	*next;
}						t_fdflist;

t_list					*ft_stock_lines(int fd);
int						ft_max_size(t_list *list);
int						**ft_stock_values(t_list *list);

#endif
