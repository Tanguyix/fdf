/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:44:55 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/20 17:17:58 by tboissel         ###   ########.fr       */
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