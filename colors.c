/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:38:35 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/20 17:20:24 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void     ft_get_color(char flag, char *av, t_map *map)
{
    if (flag == 'b')
        map->color_bottom = ft_get_rgb(av);
    else if (flag == 'p')
        map->color_peak = ft_get_rgb(av);
    else
    {
        ft_usage();
        exit(0);
    }
}

int     ft_get_rgb(char *av)
{
    int     i;
    int     nb;
    int     rgb;

    rgb = 0;
    i = 0;
    nb = 65536;
    if (av[0] != '(')
        exit(0);
    i++;
    while(av[i])
    {
        while(av[i] == ' ' || av[i] == ',')
            i++;
        rgb += nb * ft_atoi(&av[i]);
        nb /= 256;
        while(av[i] && ft_isdigit(av[i]))
            i++;
        while(!(ft_isdigit(av[i])))
            i++;
        if (nb == 0)
            break;
    }   
    return (rgb);
}