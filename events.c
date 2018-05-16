/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:50:21 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/16 11:05:06 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int    key_events(int key, void *param)
{
    if (key == 53)
        exit(0);
    return (0);
}

int     ft_exit(int key, void *param)
{
    exit(0);
    return (0);
}