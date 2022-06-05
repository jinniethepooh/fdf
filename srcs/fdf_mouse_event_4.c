/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_event_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:37:28 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/05 23:53:50 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int mousecode, t_info *info)
{
        if (mousecode == 17)
            close_window(info);
        return (0);
}