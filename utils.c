/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:44:55 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/17 18:42:49 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_get_name(t_map *map, char* av1)
{
    int     i;
    
    i = 0;
    while (av1[i])
        i++;
    while (i && av1[i] != '/')
        i--;
    if (av1[i] == '/')
        i++;
    map->name = ft_strdup(&av1[i]);
}

void    ft_usage()
{
    ft_putstr("Usage : ./fdf <fichier.fdf>\n");
}